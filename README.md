# Valhalla for Python

This spin-off project simply offers improved Python bindings to the fantastic [Valhalla project](https://github.com/valhalla/valhalla). 

The improvements to Valhalla's native bindings are:

- easier configuration of Valhalla
- re-configure the routing engine with different parameters (e.g. maximum limits) or change routing tiles
- more pythonic way for requesting via `dict` objects instead of `str`
- some utilities: decoding polylines

> Disclaimer: This is a third-party clone of Valhalla where (almost) only Python related code was changed. We regularly merge the Valhalla core to stay up-to-date.

## Planned Features

- [ ] Download tile packs for Valhalla
- [ ] Download admin & timezone DBs

## Installation
 
`pip install valhalla`

We package CPython 3.7, 3.8, 3.9 binary **wheels** for Win64, ~~MacOS X~~ (soon) and Linux distributions with `glibc>=2.24` (most modern systems, see [PEP 600](https://www.python.org/dev/peps/pep-0600/)). We **do not** offer a source distribution on PyPI. Please contact us on enquiry@gis-ops.com if you need support building the bindings for your platform.

## Usage

Typically you'd take these steps:

### 1. Configure Valhalla

Valhalla expects a config JSON to know where to put the routing tiles, applying service limits etc. If you don't have an existing Valhalla JSON, one will be created for you at the specified path. If you don't specify your own `config` dictionary and the config JSON doesn't exist, the default will apply from `valhalla.config.get_default()`. If the config JSON does exist and `config` is specified, the config file will be overwritten.

```python
from valhalla import Actor, config

# Will create valhalla.json with the default configuration
actor = Actor('./valhalla.json', tile_extract='./valhalla_tiles.tar', verbose=True)
# or pass a configuration explicitly: good for changing defaults
conf = config.get_default()
conf['mjolnir']['tile_dir'] = './'
conf['mjolnir']['service_limits']['bicycle']['max_locations'] = 500
actor = Actor('./valhalla.json', './valhalla_tiles.tar', conf)
```

### 2. Execute action (Route/Isochrone/Matrix etc.)

After you configured the service and if there are routable tiles you can call any of the Valhalla actions (see `loki.actions` for a list). The actions support the same format as a Valhalla HTTP API request, either as `dict` or as `str`.

Valhalla encodes the geometry for a routing request with [Google's polyline algorithm](https://developers.google.com/maps/documentation/utilities/polylinealgorithm) and a precision of 6. For convenience, we include a polyline decoder in `valhalla.utils.decode_polyline()`.

```python
import json
from valhalla import Actor, utils

query = {"locations": [{"lat": 42.560225, "lon": 1.575251}, {"lat": 42.553396, "lon": 1.541176}], "costing": "auto", "directions_options": {"language": "ru-RU"}}
actor = Actor('./valhalla.json', verbose=False)
route = actor.route(query)

json.dumps(route, indent=2)

# Get the geometry as coordinate array, default in [lng, lat] order
coords = utils.decode_polyline(route['trip']['legs'][0]['shape'], order='latlng')
print(coords)
```

## Release pattern

Releases of the Python wheels on PyPI will have the pattern `<bindings_version>-<YYYY-MM-DD>`, where the date information is relating to the merge date of Valhalla core (approx. midnight CE(S)T). We're planning to merge Valhalla core code once a month, unless there's critical bug fixes.
