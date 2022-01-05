# Valhalla for Python

This spin-off project simply offers packaged Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla).

Over time we will very likely deviate from Valhalla's own Python binding code to allow usages outside the scope of the core project.

## Installation
 
We package all currently supported CPython binary **wheels** for Win64, MacOS (Intel) and x64 Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform.

`pip install valhalla`

## Build

First you need to build and install valhalla. It's a submodule of this project and it's important you build it to `./lib/valhalla/build`:

```shell script
# update all of valhalla's third_party libs
git submodule update --init --recursive

cmake -B lib/valhalla/build -S lib/valhalla -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=ON -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build lib/valhalla/build -- -j$(nproc)

# Windows: set env var for setup.py and vcpkg
set VCPKG_INSTALLATION_ROOT=C:\Users\nilsn\Documents\dev\vcpkg
```

This should be enough for all platforms. For OSX and Linux the wheels have to be fixed with `auditwheel` or `delocate`.

```
pip install setuptools wheel setuptools_scm setuptools_scm_git_archive pybind11
python setup.py bdist_wheel
```

## Usage

TBD
