#!/usr/bin/env bash
set -e

cd valhalla-py

# this circumvents when I locally clone valhalla but try to reset the patches in the container
git config --global --add safe.directory /valhalla-py/upstream

# locally extend the PATH to avoid problems
PATH="${PATH}:/opt/_internal/cpython-3.10.11/bin"

# install conan
python3.10 -m pip install --upgrade pip "conan<2.0.0"
# NOTE, those paths will likely need to get updated over time
conan config set "storage.path=$PWD/upstream/conan_data"
conan install --install-folder conan_build .

# apply any patches
pushd upstream
git apply --reject --whitespace=fix ../upstream_patches/*
popd

# build valhalla
cmake -B upstream/build -S upstream/ -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DENABLE_CCACHE=OFF -DBUILD_SHARED_LIBS=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=OFF -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_DATA_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DENABLE_CCACHE=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build upstream/build -- -j$(nproc)

echo "copying all headers"
cp -arf /usr/include/curl include/linux

# protobuf is installed in /usr/local
rm -r include/linux/google
cp -arf /usr/local/include/google include/linux

# copy valhalla headers from upstream to include/common after deleting the old ones for safety reasons
# also rm the old setup.py build folder: if the version doesn't change, setuptools simply won't update the .so,
# so we'd get old builds fact.. wtf..
rm -r include/common/valhalla
cp -r upstream/valhalla include/common
if [[ -d build ]]; then
  rm -r build
fi

# copy most recent valhalla_build_config.py
cp upstream/scripts/valhalla_build_config valhalla/valhalla_build_config.py

# copy libvalhalla and libprotobuf-dev so it's available for setup.py in its most recent version
cp -f upstream/build/src/libvalhalla.a lib/linux
cp -f /usr/local/lib64/libprotobuf-lite.a lib/linux

# build the proto files into the include/linux/valhalla/proto directory before building the bindings
if [[ -d include/linux/valhalla/proto ]]; then
  rm -r include/linux/valhalla/proto
fi
mkdir -p include/linux/valhalla/proto
/usr/local/bin/protoc --proto_path=$PWD/upstream/proto --cpp_out=$PWD/include/linux/valhalla/proto $PWD/upstream/proto/*.proto

# make the bindings so we can see which libraries it exactly links to and also for testing
python3.10 -m pip install -r build-requirements.txt
python3.10 setup.py bdist_wheel

echo "copying all libraries"
deps="libcurl libz"
# prints all linked library paths
for path in $(ldd build/lib.linux-x86_64-cpython-310/valhalla/_valhalla.cpython-310-x86_64-linux-gnu.so | awk 'NF == 4 {print $3}; NF == 2 {print $1}'); do
  for dep in ${deps}; do
    echo "Copying library ${dep} from ${path}"
    if [[ ${path} == *${dep}* ]]; then
      rel_dest=lib/linux/${path##*/lib64/}
      # make the directory before
      mkdir -p $(dirname ${rel_dest})
      # follow symlinks and copy the actual file
      cp -L $path $(dirname ${rel_dest})
    fi
  done
done

# now checkout the unpatched valhalla version again
git -C upstream checkout .

for so in dist/*; do
  auditwheel repair --plat manylinux_2_28_x86_64 "${so}"
done
