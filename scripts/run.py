import os
from CONFIG import get_premake_property
os.system(os.path.join(os.path.dirname(__file__), '..', 'bin', get_premake_property('targetname') + '.exe'))