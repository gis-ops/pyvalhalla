import os
from setuptools import find_packages, setup
from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "_valhalla",
        [os.path.join("valhalla", "_valhalla.cc")],
        cxx_std=17,
        include_pybind11=False,  # use submoduled pybind11
        extra_link_args=[
            "-lvalhalla",
            "-lprotobuf-lite",
            "-lcurl",
            "-lgeos",
            "-lluajit-5.1",
            "-lsqlite3",
            "-lspatialite",
            "-DRAPIDJSON_HAS_STDSTRING=1"
        ],
        libraries=["protobuf-lite", "valhalla", "curl", "geos", "luajit-5.1", "sqlite3", "spatialite"]
    ),
]

here = os.path.abspath(os.path.dirname(__file__))

with open(os.path.join(here, "README.md"), encoding="utf-8") as f:
        long_description = "\n" + f.read()

setup(
    name="valhalla",
    description="High-level bindings to the Valhalla framework",
    long_description=long_description,
    author="Nils Nolde",
    author_email="nils@gis-ops.com",
    packages=find_packages(exclude=["tests", "*.tests", "*.tests.*", "tests.*"]),
    python_requires=">=3.7.0",
    url="https://github.com/gis-ops/valhalla-py",
    ext_package="valhalla",
    ext_modules=ext_modules,
    include_dirs=[
        "/usr/local/include",
        "third_party/date/include",
        "third_party/rapidjson/include",
        "third_party/pybind11/include"
    ],
    zip_safe=False,
    use_scm_version=True,
)
