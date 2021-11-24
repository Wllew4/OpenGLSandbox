import shutil
import os

bin_dir = os.path.join(os.path.dirname(__file__), '..', 'bin')

if not os.path.exists(bin_dir):
    os.makedirs(bin_dir)

def copy_folder_to_bin(_from: str, _to: str = ""):
    if _to == "":
        _to = _from
    in_dir = os.path.join(os.path.dirname(__file__), '..', _from)
    out_dir = os.path.join(bin_dir, _to)
    if os.path.exists(out_dir):
        shutil.rmtree(out_dir)
    shutil.copytree(in_dir, out_dir)

copy_folder_to_bin('shaders')
copy_folder_to_bin('sandbox')
copy_folder_to_bin(os.path.join('src', 'lua'), 'lua')
shutil.copy(os.path.join('lib', 'lua-5.4.2_lib64', 'lua54.dll'), bin_dir)