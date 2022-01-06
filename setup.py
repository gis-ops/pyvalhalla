import json
import logging
import os
from pathlib import Path
import sys
import platform
from setuptools import find_packages, setup
from pybind11.setup_helpers import Pybind11Extension
import pybind11

THIS_DIR = Path(__file__).parent.resolve()
VALHALLA_INC_ROOT = THIS_DIR.joinpath("lib", "valhalla", "third_party")
VALHALLA_SOURCE = str(THIS_DIR.joinpath("lib", "valhalla", "build", "src"))

include_dirs = [
    str(VALHALLA_INC_ROOT.joinpath("date", "include")),
    str(VALHALLA_INC_ROOT.joinpath("rapidjson", "include")),
    str(VALHALLA_INC_ROOT.joinpath("cpp-statsd-client", "include")),
    str(THIS_DIR.joinpath("lib", "valhalla")),
    str(THIS_DIR.joinpath("lib", platform.system().lower(), "include")),
    # some includes are referencing like <baldr/..> instead of <valhalla/baldr/..>
    str(THIS_DIR.joinpath("lib", "valhalla", "valhalla")),
    # contains headers for all platforms
    VALHALLA_SOURCE,
    pybind11.get_include()
]
libraries = list()
library_dirs = list()
extra_link_args = list()
extra_compile_args = list()

if platform.system() == "Windows":
    # I couldn't take it anymore on windows, so I just checked in all dependencies including headers
    # needs to be update here and there, but likely mainly for valhalla, fair enough!
    include_dirs.extend([
        str(THIS_DIR.joinpath("lib", "windows", "include")),
        str(VALHALLA_INC_ROOT.joinpath("dirent", "include"))
    ])
    library_dirs.append(str(THIS_DIR.joinpath("lib", "windows", "lib")))
    libraries.extend(["libprotobuf-lite", "valhalla", "libcurl", "zlib", "Ws2_32", "ole32", "Shell32"])
    extra_compile_args.extend(["-DNOMINMAX", "-DWIN32_LEAN_AND_MEAN", "-DNOGDI"])
else:
    # where libvalhalla lives
    library_dirs.extend([VALHALLA_SOURCE])
    libraries.extend(["protobuf-lite", "valhalla", "curl", "z"])
    extra_link_args.extend(["-lvalhalla", "-lprotobuf-lite", "-lcurl", "-lz"])

# do conan dependency resolution
conanfile = tuple(Path(__file__).parent.resolve().rglob('conanbuildinfo.json'))
if conanfile:
    logging.info("Using conan to resolve dependencies.")
    with conanfile[0].open() as f:
        # it's just header-only boost so far..
        include_dirs.extend(json.load(f)['dependencies'][0]['include_paths'])
else:
    logging.warning('Conan not installed and/or no conan build detected. Assuming dependencies are installed.')

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

# open README.md for PyPI
with open(os.path.join(THIS_DIR, "README.md"), encoding="utf-8") as f:
    long_description = "\n" + f.read()

setup(
    name="valhalla",
    description="High-level bindings to the Valhalla C++ library",
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
