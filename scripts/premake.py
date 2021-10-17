from CONFIG import BUILD_SYSTEM, premake_s, get_next_value

import json
import re
import os
import shutil


#   Run premake5
if shutil.which('premake5') is not None:
    os.system('premake5 ' + BUILD_SYSTEM)
else:
    print('premake5.exe not added to PATH.')
    exit(1)

configurations = list()

def find_all(string: str, key: str) -> list[int]:
    return [m.start() for m in re.finditer(key, string)]


#   Add configurations
configurations_string_indexes = find_all(premake_s, 'configurations')
for index in configurations_string_indexes:
    if premake_s[index-1] != '"':
        for name in get_next_value(premake_s, configurations_string_indexes[0]+len('configurations')):
            configurations.append({'name': name})

#   Apply properties
def apply_property(premake_name: str, vscode_name: str):
    global_values = list[str]()
    for global_values_indexes in find_all(premake_s.split('filter')[0], premake_name):
        global_values += get_next_value(premake_s, global_values_indexes)
    if global_values != []:
        for config in configurations:
            if vscode_name not in config:
                config[vscode_name] = list[str]()
            config[vscode_name] += global_values

    #   per filter
    for filter in premake_s.split('filter')[1:]:
        filter_name = filter[filter.find('configurations:')+len('configurations:'):filter.find('"', 2)]
        values = list[str]()
        # apply values
        for values_indexes in find_all(filter, premake_name):
            values = get_next_value(filter, values_indexes)
        if values != []:
            for config in configurations:
                if config['name'] == filter_name:
                    if vscode_name not in config:
                        config[vscode_name] = list[str]()
                    config[vscode_name] += values
                    break

apply_property('includedirs', 'includePath')
apply_property('defines', 'defines')
apply_property('cppdialect', 'cppStandard')
apply_property('cdialect', 'cStandard')
for config in configurations:
    if 'cppStandard' in config:
        config['cppStandard'] = config['cppStandard'][-1].lower()
    if 'cStandard' in config:
        config['cStandard'] = config['cStandard'][-1].lower()

vsconfig = {
    "configurations": configurations,
    "version": 4
}

#   Write to file
config_dir = os.path.join(os.path.dirname(__file__), '..', '.vscode')
if not os.path.exists(config_dir):
    os.makedirs(config_dir)
config_path = os.path.join(config_dir, 'c_cpp_properties.json')
write_config = open(config_path, 'w')
write_config.write(json.dumps(vsconfig, indent=4))