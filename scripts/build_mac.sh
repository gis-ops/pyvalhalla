#!/usr/bin/env bash

pip3 install conan
conan profile new default --detect
conan config set "storage.path=${PWD}/upstream/conan_data"
conan install --install-folder conan_build .

# apply any patches
pushd upstream
git apply ../upstream_patches/*
popd

# TODO: the env var can be omitted once geos 3.11 is released: https://github.com/libgeos/geos/issues/500
cmake -B upstream/build -S upstream/ -DCMAKE_OSX_DEPLOYMENT_TARGET=10.9 -DENABLE_CCACHE=OFF -DBUILD_SHARED_LIBS=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=ON -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_DATA_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DENABLE_CCACHE=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build upstream/build -- -j$(sysctl -n hw.logicalcpu)

rm -r include/darwin/*
rm -r lib/darwin

echo "copying all headers except protobuf"
deps="curl geos luajit libspatialite sqlite"
for dep in $deps; do
  for path in $(brew list ${dep} -v); do
    # find and copy the headers
    if [[ ${path} == *"/include/"* ]]; then
      rel_dest=include/darwin/${path##*/include/}
      mkdir -p $(dirname ${rel_dest})
      cp $path $(dirname ${rel_dest})
      chmod 644 ${rel_dest}
    fi
  done
done

cp -rf /usr/local/include/google include/darwin

# copy libvalhalla
mkdir -p lib/darwin
cp -f upstream/build/src/libvalhalla.a lib/darwin

# copy dependencies
cp -RL /usr/local/lib/libprotobuf-lite.dylib lib/darwin/libprotobuf-lite.32.dylib

mkdir -p include/darwin/valhalla/proto
protoc --proto_path=upstream/proto --cpp_out=include/darwin/valhalla/proto upstream/proto/*.proto

# remove build folder or we'll get weird caching stuff
if [[ -d build ]]; then
  rm -r build
fi
pip3 install -r build-requirements.txt
python3 setup.py bdist_wheel

# now checkout the unpatched valhalla version again
git -C upstream checkout .

# patch the paths delocate sees
LIBRARY_PATH="$(pwd)/lib/darwin/:$LIBRARY_PATH"

for dylib in dist/*; do
  DYLD_LIBRARY_PATH=$LIBRARY_PATH delocate-wheel -w wheelhouse "${dylib}"
done
