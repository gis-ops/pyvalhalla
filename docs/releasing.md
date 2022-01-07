## `valhalla-py` release patterns

We release entirely independently from Valhalla core. One can retrieve both versions by:

TBD

### Release scheme

We follow semantic versioning as good as we can with the following guarantees:

#### Major version change

Reflects Valhalla's major version, i.e. we can guarantee compatibility of tiles built by the same Valhalla major version.

As opposed to Valhalla itself, we also guarantee API stability (much easier to do in bindings).

#### Minor version change

The usual backwards-compatible features/deprecations.

**Note** however, that you might have to re-create the configuration JSON.

#### Patch version change

The usual minor bug fixes.

**Note** however, that you might have to re-create the configuration JSON.

### Releasing

What a struggle! I won't go in all the details and different dead-ends I tried, but dear C++ dev being (rightfully) appalled by the current design: Windows made it pretty much impossible to build the dependencies in CI. Some reasons:
- `vcpkg` dependency installation on Github Action runners takes > 45 mins
- `vcpkg` binaries can't be cached since they exceed GA free limit
- `vcpkg` installs _both_ debug & release binaries, bloating the cache abnormously. There's an option to only build release binaries, but some (e.g. `spatialite`) won't compile without debug files
- almost most important: save some resources. Why the hell would I need to build dependencies which change really rarely? Pointless.

So, decision was in the end to check in all dependencies except for boost headers, for all platforms. Slightly painful, but welcome to platform-independent packaging..

#### Procedure

We need access to all headers and libraries, so everything needs to be in `./lib`. There's no magic going on here, it's a plain copy/paste operation, our `setup.py` will configure the build correctly.

To release binding code changes, we simply push a tag and let CI take care of the rest.

To release after dependency updates (mostly Valhalla usually), it will then be a 3-stage process:
- first build and copy all dependencies for manylinux, also include the [common stuff](#common) here
- then check out the release branch on the other OSs and repeat

#### Common

- all headers to `include`
- don't forget valhalla's `third_party` repos: `date`, `rapidjson`, `statsd` & `dirent` (win-only) are needed for compiling bindings
- proto headers to `include/valhalla/proto`, which have to be compiled first, e.g.

`protoc --proto_path=lib/valhalla/proto --cpp_out=lib/valhalla/valhalla/proto lib/valhalla/proto/*.proto`

#### Linux

Fire up the `ghcr.io/gis-ops/manylinux:valhalla_py` image which has all dependencies installed and build valhalla:

TODO: describe the process, maybe add a small script for building and copying the headers & libs

- copy the .so deps: `ldd ${jail}/bin/* | egrep -o '\[^ \]*/lib\[^ \]*\[.\]\[0-9\]' | xargs -I{} -P1 sudo cp -v {} ${jail}{}` (from [here](https://unix.stackexchange.com/a/120017))

#### Mac OS

TODO: describe process, maybe add a small script to build valhalla and copy headers & libs (maybe some `brew list` or so?)

#### Windows

The only area where Windows is shining: makes it really simple, just copy the headers & libs from `vcpkg`.
