# Valhalla for Python
[![Master Push](https://github.com/gis-ops/pyvalhalla/actions/workflows/push_master.yml/badge.svg)](https://github.com/gis-ops/pyvalhalla/actions/workflows/push_master.yml)

This spin-off project simply offers packaged Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla).

Over time we will very likely deviate from Valhalla's own Python binding code to allow usages outside the scope of the core project. Refer to our [release pattern](./docs/releasing.md) to learn more about the versioning of this project.

**Note**, the performance boost using these bindings compared to requesting an HTTP service is tremendous: on 500 random routes in Berlin, the bindings take 27 secs while HTTP on localhost takes 127 secs.

## Installation
 
We distribute all 4 currently developed CPython versions as **binary wheels** for Win64, MacOS (Intel) and x86_64 Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform/distribution.

`pip install pyvalhalla`

**Note**, to install from PyPI as a **Linux** user you must have `pip` version 20.3 or greater installed.

## Usage

Find a more extended notebook in `./examples`, e.g. how to [use the actor](./examples/actor_examples.ipynb).

Before using the Python bindings you need to have access to a routable Valhalla graph. Either install Valhalla from source and built the graph from OSM compatible data or use our [Valhalla docker image](https://github.com/gis-ops/docker-valhalla) for a painless experience, e.g. this will build the routing graph for Andorra in `./custom_files`:

```shell
docker run --rm --name valhalla_gis-ops -p 8002:8002 -v $PWD/custom_files:/custom_files -e tile_urls=https://download.geofabrik.de/europe/andorra-latest.osm.pbf gisops/valhalla:latest
```

Once you have created a graph locally, you can use it like this:

```python
from valhalla import Actor, get_config, get_help

# generate configuration
config = get_config(tile_extract='./custom_files/valhalla_tiles.tar', verbose=True)

# print the help for specific config items (has the same structure as the output of get_config()
print(get_help()["service_limits"]["auto"]["max_distance"])

# instantiate Actor to load graph and call actions
actor = Actor(config)
route = actor.route({"locations": [...]})
```

## License

`pyvalhalla` is licensed with GPLv2, see [LICENSE](./LICENSE).
