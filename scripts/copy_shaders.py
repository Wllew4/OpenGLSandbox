import shutil
import os

in_dir = os.path.join(os.path.dirname(__file__), '..', 'shaders')
out_dir = os.path.join(os.path.dirname(__file__), '..', 'bin', 'shaders')
shutil.rmtree(out_dir)
shutil.copytree(in_dir, out_dir)