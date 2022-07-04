#!/usr/bin/env bash

# build valhalla first in our manylinux image
echo "building valhalla.."
docker exec python-build /valhalla-py/scripts/build_linux_do.sh
