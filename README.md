# Valhalla for Python
[![Master Push](https://github.com/gis-ops/pyvalhalla/actions/workflows/push_master.yml/badge.svg)](https://github.com/gis-ops/pyvalhalla/actions/workflows/push_master.yml)

This spin-off project simply offers packaged Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla).

Over time we will very likely deviate from Valhalla's own Python binding code to allow usages outside the scope of the core project.

## Installation
 
We distribute all 4 currently supported CPython versions as binary **wheels** for Win64, MacOS (Intel) and x86_64 Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform/distribution.

`pip install pyvalhalla`

**Note**, to install from PyPI as a **Linux** user you must have `pip` version 20.3 or greater installed.

## Usage

Before using the Python bindings you need to have access to a routable Valhalla graph. Either install Valhalla from source and built the graph from OSM compatible data or use our [Valhalla docker image](https://github.com/gis-ops/docker-valhalla) for a painless experience.

Once you have created a graph locally, you can use it like this:
```python
from valhalla import Actor, get_config

# generate configuration
config = get_config(tile_extract='path/to/extract.tar', verbose=True)

# instantiate Actor to load graph and call actions
actor = Actor(config)
route = actor.route({"locations": [...]})
```

## License

`pyvalhalla` is licensed with GPLv2, see [LICENSE](./LICENSE).
