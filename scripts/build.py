from build_shaders import build_shaders
build_shaders()

import os
import shutil

from CONFIG import BUILD_SYSTEM, MAKE_BINARY, get_premake_property

bin_path = os.path.join(
    os.path.dirname(__file__), '..',
    get_premake_property('targetdir'),
    get_premake_property('targetname') + '.exe')

if os.path.exists(bin_path):
    print('Removing last sucessful build')
    os.remove(bin_path)

workspace_name = get_premake_property('workspace')

supported_vs_versions = [
    'vs2019',   'vs2017',
    'vs2015',   'vs2013',
    'vs2012',   'vs2010',
    'vs2008',   'vs2005'
]

if BUILD_SYSTEM in supported_vs_versions:
    workspace_name += '.sln'
    sln_path = os.path.join(os.path.dirname(__file__), '..', workspace_name)
    if shutil.which('msbuild') is not None:
	    print('Building with Visual Studio: ' + workspace_name)
	    os.system('msbuild ' + workspace_name)
    else:
	    print('Could not find msbuild! Make sure it is added to PATH')
elif BUILD_SYSTEM == 'gmake2':
    if shutil.which(MAKE_BINARY) is not None:
        print('Building with GNU Make:')
        os.system(MAKE_BINARY)
    else:
        print('Could not find ' + MAKE_BINARY + '! Make sure it is added to PATH')