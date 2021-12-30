import os
from pathlib import Path
import sys
from sys import platform
from setuptools import find_packages, setup
from pybind11.setup_helpers import Pybind11Extension

VCPKG_ROOT = os.getenv('VCPKG_ROOT', '')

include_dirs = [
    "third_party/date/include",
    "third_party/rapidjson/include",
    "third_party/pybind11/include",
    "third_party/dirent/include"
]
libraries = list()
library_dirs = list()
extra_link_args = list()
extra_compile_args = list()

if platform == "win32":
    if not VCPKG_ROOT:
        print("ERROR. Set the environment variable VCPKG_ROOT to the absolute path of the vcpkg root directory.")
        sys.exit(1)
    include_dirs.extend([
        r'C:\Program Files (x86)\valhalla\include',
        str(Path(VCPKG_ROOT).joinpath('installed', 'x64-windows', 'include').resolve()),
        r'C:\.conan\bc7df6\1\include'  # TODO: remove this once we know how to get conan's include dir
    ])

    library_dirs.extend([
        r"C:\Program Files (x86)\valhalla\lib",
        str(Path(VCPKG_ROOT).joinpath('installed', 'x64-windows', 'lib').resolve())
    ])
    extra_link_args.append("/clp:ErrorsOnly")
elif platform == "linux":
    extra_link_args.extend(["-lvalhalla", "-lprotobuf-lite", "-lcurl"])

ext_modules = [
    Pybind11Extension(
        "_valhalla",
        [os.path.join("valhalla", "_valhalla.cc")],
        cxx_std=11,
        include_pybind11=False,  # use submodule'd pybind11
        include_dirs=include_dirs,
        extra_link_args=extra_link_args,
        extra_compile_args=extra_compile_args,
        libraries=["protobuf-lite", "valhalla", "curl"]  #, "geos", "luajit-5.1", "sqlite3", "spatialite"]
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
    include_dirs=include_dirs,
    zip_safe=False,
    use_scm_version=True,
)
