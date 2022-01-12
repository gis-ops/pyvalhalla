#!/usr/bin/env bash
set -e

cd valhalla-py

# install conan
apt-get update
apt-get install -y python3-pip
pip3 install conan
conan config set "storage.path=$PWD/upstream/conan_data"
conan install --install-folder upstream/conan_build upstream/

# apply any patches
pushd upstream
git apply ../upstream_patches/*
popd

# build valhalla
cmake -B upstream/build -S upstream/ -DENABLE_CCACHE=OFF -DBUILD_SHARED_LIBS=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=ON -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DENABLE_CCACHE=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build upstream/build -- -j$(nproc)

# reset valhalla upstream
git -C upstream checkout .

echo "copying all headers"
deps="libcurl4-openssl-dev libgeos++-dev libgeos-dev libluajit-5.1-dev libprotobuf-dev libspatialite-dev libsqlite3-dev"
for dep in $deps; do
  for path in $(dpkg -L ${dep}); do
    # find and copy the headers
    if [[ ${path} == *".h"* ]]; then
      if [[ ${path} == *"/x86_64-linux-gnu/"* ]]; then
        rel_dest=include/linux/${path##*/x86_64-linux-gnu/}
      else
        rel_dest=include/linux/${path##*/include/}
      fi
      mkdir -p $(dirname ${rel_dest})
      cp $path $(dirname ${rel_dest})
    fi
  done
done

# copy valhalla headers from upstream to lib/common
rm -r include/common/valhalla
cp -r upstream/valhalla include/common
mv include/common/valhalla/config.h.cmake include/common/valhalla/config.h
mv include/common/valhalla/valhalla.h.in include/common/valhalla/valhalla.h

# copy libvalhalla so it's available for setup.py in its most recent version
# patch the files names of some headers
cp -f upstream/build/src/libvalhalla.a lib/linux

# make the bindings so we can see which libraries it exactly links to and also for testing
/opt/python/cp310-cp310/bin/pip install -r build-requirements.txt
/opt/python/cp310-cp310/bin/python3 setup.py bdist_wheel

echo "copying all libraries"
deps="libprotobuf-lite libcurl libz"
# prints all linked library paths
for path in $(ldd build/lib.linux-x86_64-3.10/valhalla/_valhalla.cpython-310-x86_64-linux-gnu.so | awk 'NF == 4 {print $3}; NF == 2 {print $1}'); do
  for dep in ${deps}; do
    if [[ ${path} == *${dep}* ]]; then
      if [[ ${path} == *"/x86_64-linux-gnu/"* ]]; then
        rel_dest=lib/linux/${path##*/x86_64-linux-gnu/}
      else
        rel_dest=lib/linux/${path##*/lib/}
      fi
      # make the directory before
      mkdir -p $(dirname ${rel_dest})
      # follow symlinks and copy the actual file
      cp -L $path $(dirname ${rel_dest})
    fi
  done
done

# build the proto files into the include/linux/valhalla/proto directory
mkdir -p include/linux/valhalla/proto
/usr/bin/protoc --proto_path=upstream/proto --cpp_out=include/linux/valhalla/proto upstream/proto/*.proto

<<<<<<< HEAD
# now checkout the unpatched valhalla version again
git -C upstream checkout .

=======
>>>>>>> master
for so in dist/*; do
  auditwheel repair --plat manylinux_2_24_x86_64 "${so}"
done
