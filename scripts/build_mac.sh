echo "copying all headers"
deps="curl geos luajit protobuf libspatialite sqlite"
for dep in $deps; do
  for path in $(brew list ${dep} -v); do
    # find and copy the headers
    if [[ ${path} == *".h"* ]]; then
      rel_dest=include/darwin/${path##*/include/}
      mkdir -p $(dirname ${rel_dest})
      cp $path $(dirname ${rel_dest})
    fi
  done
done

# copy libvalhalla
mkdir -p lib/darwin
cp -f upstream/build/src/libvalhalla.a lib/darwin

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

delocate-wheel -w wheelhouse dist/*
