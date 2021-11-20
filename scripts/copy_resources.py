import shutil
import os

in_dir = os.path.join(os.path.dirname(__file__), '..', 'shaders')
out_dir = os.path.join(os.path.dirname(__file__), '..', 'bin', 'shaders')
if(os.path.exists(out_dir)):
    shutil.rmtree(out_dir)
shutil.copytree(in_dir, out_dir)

in_dir = os.path.join(os.path.dirname(__file__), '..', 'sandbox')
out_dir = os.path.join(os.path.dirname(__file__), '..', 'bin', 'sandbox')
if(os.path.exists(out_dir)):
    shutil.rmtree(out_dir)
shutil.copytree(in_dir, out_dir)