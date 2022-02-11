#!/usr/bin/env bash

pip3 install conan
conan profile new default --detect
conan config set "storage.path=${PWD}/upstream/conan_data"
conan install --install-folder upstream/conan_build .

# apply any patches
pushd upstream
git apply --reject --whitespace=fix ../upstream_patches/*
popd

# TODO: the env var can be omitted once geos 3.11 is released: https://github.com/libgeos/geos/issues/500
CXXFLAGS=-DGEOS_INLINE cmake -B upstream/build -S upstream/ -DCMAKE_OSX_DEPLOYMENT_TARGET=10.9 -DENABLE_CCACHE=OFF -DBUILD_SHARED_LIBS=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=ON -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DENABLE_CCACHE=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build upstream/build -- -j$(sysctl -n hw.logicalcpu)

echo "copying all headers"
deps="curl geos luajit protobuf libspatialite sqlite"
for dep in $deps; do
  for path in $(brew list ${dep} -v); do
    # find and copy the headers
    if [[ ${path} == *"/include/"* ]]; then
      rel_dest=include/darwin/${path##*/include/}
      if [[ -f ${path} ]]; then
        mkdir -p $(dirname ${rel_dest})
        cp $path $(dirname ${rel_dest})
      fi
    fi
  done
done

# symlink libs, otherwise gcc/g++ can't find e.g. libprotobuf-lite.28.dylib (while it does find libprotobuf-lite.dylib)
push lib/darwin
ln -s libprotobuf-lite.28.dylib libprotobuf-lite.dylib
popd

# copy libvalhalla
mkdir -p lib/darwin
cp -f upstream/build/src/libvalhalla.a lib/darwin

# remove setuptools build folder so we build a fresh _valhalla.so every tiem
if [[ -d build ]]; then
  rm -r build
fi

# make the bindings so we can see which libraries it exactly links to and also for testing
pip3 install -r build-requirements.txt
python3 setup.py bdist_wheel

echo "copying all libraries"
deps="libprotobuf-lite"
# prints all linked library paths
for path in $(otool -L build/lib.macosx-*/valhalla/*.so | awk '{print $1}'); do
  for dep in ${deps}; do
    if [[ ${path} == *${dep}* ]]; then
      rel_dest=lib/darwin/${path##*/lib/}
      # make the directory before
      mkdir -p $(dirname ${rel_dest})
      # follow symlinks and copy the actual file
      cp -L $path $(dirname ${rel_dest})
    fi
  done
done

mkdir -p include/darwin/valhalla/proto
protoc --proto_path=upstream/proto --cpp_out=include/darwin/valhalla/proto upstream/proto/*.proto

# now checkout the unpatched valhalla version again
git -C upstream checkout .

# patch the paths delocate sees
LIBRARY_PATH="$(pwd)/lib/darwin/:$LIBRARY_PATH

for dylib in dist/*; do
  DYLD_LIBRARY_PATH=$LIBRARY_PATH delocate-wheel -w wheelhouse "${dylib}"
done
