## `valhalla-py` release patterns

We release independently from Valhalla core. One can retrieve both by:

```python
import valhalla
print(valhalla.__version__)
print(valhalla.__valhalla_commit__)
```

### Release scheme

We follow semantic versioning as good as we can with the following guarantees:

#### Major version change

Reflects Valhalla's major version, i.e. we can guarantee compatibility of tiles built by the same Valhalla major version.

As opposed to Valhalla itself, we also guarantee API stability (much easier to do in bindings).

#### Minor version change

Does not reflect Valhalla's minor version!

The usual backwards-compatible features/deprecations, often forward-compatible stuff (e.g. additional request parameters).

**Note** however, that you might have to re-create the configuration JSON.

#### Patch version change

Does not reflect Valhalla's patch version!

The usual minor bug fixes.

**Note** however, that you might have to re-create the configuration JSON.

### Releasing

What a struggle! I won't go in all the details and different dead-ends I tried, but dear C++ dev being (rightfully) appalled by the current design: Windows made it pretty much impossible to build the dependencies in CI. Some reasons:
- `vcpkg` dependency installation on Github Action Windows runners takes > 45 mins
- `vcpkg` dependency binaries can't be cached since they exceed GA free limit
- `vcpkg` installs _both_ debug & release binaries, bloating the cache abnormously. There's an option to only build release binaries, but some (e.g. `spatialite`) won't compile without debug files
- almost most important: save some resources. Why the hell would I need to build dependencies which change really rarely? Pointless.

So, decision was in the end to check in all dependencies except for boost headers, for all platforms. Slightly painful, but welcome to platform-independent packaging..

#### Procedure

We need access to all headers and libraries, so everything needs to be in `./include` `./lib`. There's no magic going on here, it's a plain copy/paste operation, our `setup.py` will configure the build correctly.

To release binding code changes, we simply push a tag and let CI take care of the rest.

To release after dependency updates (mostly Valhalla usually), it will then be a 3-stage process:
- first build and copy all dependencies for manylinux, also include the [common stuff](#common) here
- then check out the release branch on the other OSs and repeat
- finally `git tag` & `git push --tags`

#### Common

- all header-only libraries are safe to share in `./include/common`
- valhalla headers can be shared too
- don't forget valhalla's `third_party` repos: `date`, `rapidjson`, `statsd`, `pybind` & `dirent` (win-only) are needed for compiling bindings

Proto headers have to be compiled on each platform separately.

#### Linux

Fire up the `ghcr.io/gis-ops/manylinux:valhalla_py` image which has all dependencies installed and build valhalla:

```
docker run -dt -v $PWD:/valhalla-py --name valhalla-py ghcr.io/gis-ops/manylinux:valhalla_py
./scripts/build_linux.sh
sudo chown -R nilsnolde:nilsnolde .
```

That'll take care of all the header & library copying, proto compilation etc. It'll also build a wheel to `./wheelhouse`.

- **add the built valhalla commit and add the current version in __init__.py**

#### Mac OS

Pretty identical to Linux, just we don't need a docker container of course:
```
./scripts/build_mac.sh
```

Call 911 if this doesn't work!;)

#### Windows

First build Valhalla:
```
cmake -Bupstream/build -Supstream -DENABLE_TOOLS=OFF -DENABLE_HTTP=OFF -DENABLE_DATA_TOOLS=ON -DENABLE_PYTHON_BINDINGS=ON -DENABLE_SERVICES=OFF -DENABLE_TESTS=OFF -DENABLE_CCACHE=OFF -DENABLE_COVERAGE=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_SINGLE_FILES_WERROR=OFF  -DLUA_INCLUDE_DIR=C:\Users\nilsn\Documents\dev\vcpkg\installed\x64-windows\include\luajit -DLUA_LIBRARIES=C:\Users\nilsn\Documents\dev\vcpkg\installed\x64-windows\lib\lua51.lib -DPython_EXECUTABLE=C:\Users\nilsn\AppData\Local\Programs\Python\Python39\python.exe -DPython_LIBRARIES=C:\Users\nilsn\AppData\Local\Programs\Python\Python39\libs\python39.lib -DPython_INCLUDE_DIRS=C:\Users\nilsn\AppData\Local\Programs\Python\Python39\include -DCMAKE_TOOLCHAIN_FILE=C:\Users\nilsn\Documents\dev\vcpkg\scripts\buildsystems\vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 16 2019" -T host=x64 -A x64
cmake --build upstream/build --config Release --target valhalla -- -j 8
protoc.exe --proto_path=upstream/proto --cpp_out=include/windows/valhalla/proto upstream/proto/*.proto

# protobuf 3.12.3 seems to have problems with spelling: https://github.com/protocolbuffers/protobuf/issues/7522
# need to patch here:
# replace all occurrences of "AuxillaryParseTableField" with "AuxiliaryParseTableField"
```

The only area where Windows is shining: makes it really simple, just copy the headers & libs from `vcpkg`.
