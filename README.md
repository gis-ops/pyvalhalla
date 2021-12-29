# Valhalla for Python

This spin-off project simply offers improved Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla). 

## Installation
 
`pip install valhalla`

We package CPython 3.7, 3.8, 3.9 binary **wheels** for Win64, MacOS X and Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform.

## Build

First you need to build and install valhalla. On Linux I use:

```shell script
cmake -B build -DENABLE_BENCHMARKS=OFF -DENABLE_PYTHON_BINDINGS=OFF -DENABLE_TESTS=OFF -DENABLE_TOOLS=OFF -DENABLE_SERVICES=OFF -DENABLE_HTTP=OFF -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build -- -j$(nproc)
cmake --build . --target install
```

This should be enough for all platforms. For OSX and Linux the wheels have to be fixed with `auditwheel` or `delocate`.

```
pip install setuptools wheel setuptools_scm setuptools_scm_git_archive pybind11
python setup.py bdist_wheel
```

## Usage

TBD
