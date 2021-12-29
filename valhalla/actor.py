import json
from typing import Union, Callable

from ._valhalla import _Actor


def decorator(func):
    def wrapped(*args):
        # args[0] is self
        if isinstance(args[1], dict):
            return json.loads(func(args[0], json.dumps(args[1])))
        elif not isinstance(args[1], str):
            raise ValueError("Request must be either of type str or dict")
        return func(*args)
    return wrapped


class Actor(_Actor):
    def __init__(self, config_file: str, tile_extract: str = "", config: dict = {}, verbose: bool = False) -> None:
        super().__init__(config_file, tile_extract, config, verbose)
    
    @decorator
    def route(self, req: Union[str, dict]):
        return super().Route(req)

    @decorator
    def locate(self, req: Union[str, dict]):
        return super().Locate(req)

    @decorator
    def isochrone(self, req: Union[str, dict]):
        return super().Isochrone(req)

    @decorator
    def matrix(self, req: Union[str, dict]):
        return super().Matrix(req)

    @decorator
    def trace_route(self, req: Union[str, dict]):
        return super().TraceRoute(req)

    @decorator
    def trace_attributes(self, req: Union[str, dict]):
        return super().TraceAttributes(req)

    @decorator
    def height(self, req: Union[str, dict]):
        return super().Height(req)

    @decorator
    def expansion(self, req: Union[str, dict]):
        return super().Expansion(req)

    @decorator
    def centroid(self, req: Union[str, dict]):
        return super().Centroid(req)

    @decorator
    def status(self, req: Union[str, dict]):
        return super().Status(req)
