# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/).

**Unreleased** is available in Github's `master` branch, but not on PyPI.

## Unreleased

_Valhalla version 3.3.0_

## [3.1.1](https://pypi.org/project/pyvalhalla/3.1.1/) - 2023-04-16

_Valhalla version 3.3.0_

### FIXED

- `Actor.optimized_route` called Valhalla's `_Actor.route`

## [3.1.0](https://pypi.org/project/pyvalhalla/3.1.0/) - 2023-04-13

_Valhalla version 3.3.0_

### CHANGED

- Mac OSX support only from 10.15 on
- bumped Valhalla version to 3.3.0

### REMOVED

- deprecated `transit_available` endpoint

## [3.0.4](https://pypi.org/project/pyvalhalla/3.0.4/) - 2023-04-12

_Valhalla version 3.1.4_

### CHANGED

- added optimized to Python wrapper [#27](https://github.com/gis-ops/pyvalhalla/pull/27)

## [3.0.3](https://pypi.org/project/pyvalhalla/3.0.3/) - 2022-09-11

_Valhalla version 3.1.4_

### CHANGED

- link protobuf statically for Linux so apps like QGIS with embedded python interpreters can use the PyPI versions

## [3.0.2](https://pypi.org/project/pyvalhalla/3.0.2/) - 2022-03-10

_Valhalla version 3.1.4_

### ADDED

- `valhalla.get_help()` to return valhalla_build_config help dictionary

## [3.0.1](https://pypi.org/project/pyvalhalla/3.0.1/) - 2022-03-08

_Valhalla version 3.1.4_

### Fixed

- Actor wouldn't initialize if either tile_dir OR tile_extract wasn't present; we only need of one them

## [3.0.0](https://pypi.org/project/pyvalhalla/3.0.0/) - 2022-03-08

_Valhalla version 3.1.4_

### First release
