import os
from pathlib import Path
import sys
from sys import platform
from setuptools import find_packages, setup
from pybind11.setup_helpers import Pybind11Extension

VCPKG_ROOT = os.getenv('VCPKG_ROOT', '')
CONAN_ROOT = os.getenv('CONAN_ROOT', '')

include_dirs = [
    "third_party/date/include",
    "third_party/rapidjson/include",
    "third_party/pybind11/include",
    "third_party/cpp-statsd-client/include"
]
libraries = list()
library_dirs = list()
extra_link_args = list()
extra_compile_args = list()

if platform == "win32":
    if not VCPKG_ROOT:
        print("ERROR. Set the environment variable VCPKG_ROOT to the absolute path of the vcpkg root directory.")
        sys.exit(1)
    if not CONAN_ROOT:
        print("ERROR. Set the environment variable CONAN_ROOT to the absolute path of the conan's include's parent directory.")

    PROGRAM_FILES = os.getenv('programfiles(x86)')
    include_dirs.extend([
        f"{str(Path(CONAN_ROOT).joinpath('include'))}"
        f'{str(Path(PROGRAM_FILES).joinpath("valhalla", "include"))}',
        "third_party/dirent/include",
        str(Path(VCPKG_ROOT).joinpath('installed', 'x64-windows', 'include').resolve())
    ])
    library_dirs.extend([
        f'{str(Path(PROGRAM_FILES).joinpath("valhalla", "lib"))}',
        str(Path(VCPKG_ROOT).joinpath('installed', 'x64-windows', 'lib').resolve())
    ])
    libraries.extend(["libprotobuf-lite", "valhalla", "libcurl", "zlib", "Ws2_32", "ole32", "Shell32"])
    extra_compile_args.extend(["-DNOMINMAX", "-DWIN32_LEAN_AND_MEAN", "-DNOGDI"])

elif platform == "linux":
    extra_link_args.extend(["-lvalhalla", "-lprotobuf-lite", "-lcurl", "-lz"])
    libraries.extend(["protobuf-lite", "valhalla", "curl", "z"])

ext_modules = [
    Pybind11Extension(
        "_valhalla",
        [os.path.join("valhalla", "_valhalla.cc")],
        cxx_std=14,
        include_pybind11=False,  # use submodule'd pybind11
        library_dirs=library_dirs,
        include_dirs=include_dirs,
        extra_link_args=extra_link_args,
        extra_compile_args=extra_compile_args,
        libraries=libraries,  #, "geos", "luajit-5.1", "sqlite3", "spatialite"]
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
    zip_safe=False,
    use_scm_version=True,
)
