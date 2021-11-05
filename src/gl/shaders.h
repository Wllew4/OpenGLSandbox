/*	build_shaders.py loads shaders into this header at compile time.
 *	This makes the program more portable as the shader sources are
 *	included in the binary.
 */
#pragma once
constexpr char* Standard_frag="#version 400\n"
"\n"
"out vec4 color;\n"
"\n"
"in vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    color = vec4(frag_color, 1.0);\n"
"}";
constexpr char* Standard_vert="#version 400\n"
"\n"
"layout(location = 0) in vec2 a_vertex;\n"
"\n"
"out vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    frag_color = vec3(0.25, 0.25, 1.0);\n"
"    gl_Position = vec4(a_vertex, 0.0, 1.0);\n"
"}";
