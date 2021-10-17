#   Premake build system setting. Set to vs2019 or gmake2
BUILD_SYSTEM = 'vs2019'
#   Binary for GNU Make. Make sure this is added to PATH on Windows
MAKE_BINARY = 'make'


#   Backend global utilities

#   Get single property from premake5.lua
def get_premake_property(property: str) -> str:
    return get_next_value(premake_s, premake_s.find(property))[0]

#   Open premake5.lua
from io import TextIOWrapper
import os
def safe_open(file: str, mode: str) -> TextIOWrapper:
    if os.path.exists(file):
        return open(file, mode)
    else:
        print('Failed to open ' + file)
        exit(2)
premake_lua_path = os.path.join(os.path.dirname(__file__), '..', 'premake5.lua')
premake_s = safe_open(premake_lua_path, 'r').read()

#   Get value after identifier
import json
def get_next_value(string: str, index: int) -> list[str]:
    while string[index] != '"' and string[index] != '{':
        index += 1
    if string[index] == '"':
        index += 1
        front_trim = string[index:]
        return [front_trim[:front_trim.find('"', 1)]]
    if string[index] == '{':
        front_trim = string[index:]
        return json.loads(front_trim[:front_trim.find('}') + 1].strip().replace('{','[').replace('}',']'))