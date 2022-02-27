# Valhalla for Python
[![Master Push](https://github.com/gis-ops/valhalla-py/actions/workflows/push_master.yml/badge.svg)](https://github.com/gis-ops/valhalla-py/actions/workflows/push_master.yml)

This spin-off project simply offers packaged Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla).

Over time we will very likely deviate from Valhalla's own Python binding code to allow usages outside the scope of the core project.

## Installation
 
We distribute all 4 currently supported CPython versions as binary **wheels** for Win64, MacOS (Intel) and x86_64 Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform.

`pip install valhalla-py`

**Note**, to install from PyPI as a **Linux** user you must have at least `pip` version 20.3 or greater installed.

## Usage

TODO

## License

`valhalla-py` is licensed with GPLv2, see [LICENSE](./LICENSE).
