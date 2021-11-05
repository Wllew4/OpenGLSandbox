import os

def comment(file):
    file.write('/*\tbuild_shaders.py loads shaders into this header at compile time.\n')
    file.write(' *\tThis makes the program more portable as the shader sources are\n')
    file.write(' *\tincluded in the binary.\n')
    file.write(' */\n')

def build_shaders():
    shaders_h = open(os.path.join(os.path.dirname(__file__), '..', 'src', 'gl', 'shaders.h'), 'w')
    comment(shaders_h)
    shaders_h.write('#pragma once\n')

    shader_dir = os.path.join(os.path.dirname(__file__), '..', 'shaders')
    for filename in os.listdir(shader_dir):
        source = open(os.path.join(shader_dir, filename), 'r').read()
        shaders_h.write('constexpr char* ')
        shaders_h.write(filename.replace('.', '_'))
        shaders_h.write('=\"')
        shaders_h.write(source.replace('\n', '\\n\"\n\"'))
        shaders_h.write('\";\n')
        pass
    pass