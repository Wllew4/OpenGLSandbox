/*	build_shaders.py loads shaders into this header at compile time.
 *	This makes the program more portable as the shader sources are
 *	included in the binary.
 */
#pragma once
const char* HelloTriangle_frag="#version 400\n"
"\n"
"out vec4 color;\n"
"\n"
"in vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    color = vec4(frag_color, 1.0);\n"
"}";
const char* HelloTriangle_vert="#version 400\n"
"\n"
"in vec3 vertex;\n"
"in vec3 color;\n"
"\n"
"out vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    frag_color = color;\n"
"    gl_Position = vec4(vertex, 1.0);\n"
"}";
