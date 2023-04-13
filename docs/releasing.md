## `pyvalhalla` release patterns

We release independently of Valhalla core but adhere to its major version. One can retrieve both by:

```python
import valhalla
print(valhalla.__version__)
print(valhalla.__valhalla_commit__)
```

### Release scheme

We follow semantic versioning as good as we can with the following guarantees:

#### Major version change

Reflects Valhalla's major version, i.e. we can guarantee compatibility of tiles built by the same Valhalla major version.

Because of that you can't expect full API stability, though we do our best.

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

Fire up the `ghcr.io/gis-ops/manylinux:2_28_valhalla_python` image which has all dependencies installed and build valhalla:

```
docker run -dt -v $PWD:/valhalla-py --name valhalla-py ghcr.io/gis-ops/manylinux:2_28_valhalla_python
./scripts/build_linux.sh
sudo chown -R nilsnolde:nilsnolde .
```

That'll take care of all the header & library copying, proto compilation etc. It'll also build a wheel to `./wheelhouse`.

- **add the built valhalla commit in __init__.py**

#### Mac OS

> Note, for OSX we locally built protobuf from source (currently 3.21.5) as the `brew` version is not compiled to work with lower OSX versions:
  ```
  cd custom_protobuf
  cmake -B build -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -Dprotobuf_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=ON
  make -C build -j8
  sudo make -C build install
  ```


Pretty identical to Linux, just we don't need a docker container of course:
```
./scripts/build_mac.sh
```

To test it worked:

```
pip uninstall pyvalhalla
pip install wheelhouse/pyvalhalla-xxx.whl
python -c "from valhalla import Actor; a = Actor('valhalla.json')"
```

#### Windows

First build Valhalla (or set up your `.vscode/settings.json` properly, hint: `cmake.sourceDirectory/buildDirectory`):
```
cmake -Bupstream/build -Supstream -DENABLE_TOOLS=OFF -DENABLE_HTTP=OFF -DENABLE_DATA_TOOLS=OFF -DENABLE_PYTHON_BINDINGS=OFF -DENABLE_SERVICES=OFF -DENABLE_TESTS=OFF -DENABLE_CCACHE=OFF -DENABLE_COVERAGE=OFF -DENABLE_BENCHMARKS=OFF -DENABLE_SINGLE_FILES_WERROR=OFF -DCMAKE_TOOLCHAIN_FILE=C:\Users\nilsn\dev\cpp\vcpkg\scripts\buildsystems\vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 17 2022" -T host=x64 -A x64
cmake --build upstream/build --config Release --target valhalla -j 8 -- /clp:ErrorsOnly /p:BuildInParallel=true /m:8
protoc.exe --proto_path=upstream/proto --cpp_out=include/windows/valhalla/proto upstream/proto/*.proto
```

Since `3.3.0` it also needs `dirent.h` from Valhalla's `third_party/dirent`.

The only area where Windows is shining: makes it really simple, just copy the headers & libs from `vcpkg`. **Note**, it'll need the DLLs, **not** the static `.lib`s.
