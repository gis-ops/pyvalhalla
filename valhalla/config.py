import json
import warnings
from pathlib import Path

_global_config = dict()


def get_default() -> dict:
    """Returns the default Valhalla configuration."""
    from .valhalla_build_config import config as _config, Optional as _optional
    c = _config.copy()

    # replace the "optional" values we get back from the config generator
    # for optional str "", for optional int 0
    for section in ("mjolnir", "statsd"):
        for k, v in c[section].items():
            if isinstance(v, _optional):
                c[section][k] = ""

    return c


def get_help() -> dict:
    from .valhalla_build_config import help_text as _help_text
    """Returns the help texts to the Valhalla configuration."""
    return _help_text


def _create_config(path: str, tile_extract: str, c: dict, verbose: bool):
    # set a global config so that other modules can work with it
    global _global_config
    conf = c.copy()

    path: Path = Path(path).resolve()

    if path.exists() and not conf:
        # use the existing file if one exists and no config was passed
        with open(path) as f:
            conf = json.load(f)
    elif not conf:
        # if the file doesn't exist, create it and get the default config
        conf = get_default()
        path.parent.mkdir(exist_ok=True, parents=True)

    # get tile extract path
    tile_extract = Path(tile_extract or conf['mjolnir']['tile_extract'])
    tile_dir = Path(conf['mjolnir']['tile_dir'])
    if (not tile_extract.is_file() or not tile_extract.suffix == '.tar') and not tile_dir.is_dir():
        raise ValueError("Either mjolnir.tile_extract or mjolnir.tile_dir need to point at valid graphs.".format(tile_extract.resolve()))
    conf['mjolnir']['tile_extract'] = str(tile_extract.resolve())
    
    # Write the convenience stuff
    conf["loki"]["logging"]["type"] = "std_out" if verbose is True else ""

    # Finally write the config to the filesystem
    with open(path, 'w') as f:
        json.dump(conf, f, indent=2)

    _global_config = conf

    return
