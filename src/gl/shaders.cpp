/*	build_shaders.py loads shaders into this header at compile time.
 *	This makes the program more portable as the shader sources are
 *	included in the binary.
 */
const char* Circle_frag="#version 400\n"
"\n"
"out vec4 color;\n"
"\n"
"in vec3 frag_color;\n"
"in vec2 vert;\n"
"\n"
"void main()\n"
"{\n"
"    vec2 origin = vec2(0.0, 0.0);\n"
"    float d = sqrt( pow(vert.x-origin.x,2) + pow(vert.y-origin.y,2) );\n"
"    float r = 0.5;\n"
"\n"
"    if(d >= r)\n"
"    {\n"
"        color = vec4(frag_color, 0.0);\n"
"    }\n"
"    else\n"
"    {\n"
"        color = vec4(frag_color, 1.0);\n"
"    }\n"
"}";
const char* Circle_vert="#version 400\n"
"\n"
"in vec2 vertex;\n"
"in vec3 color;\n"
"\n"
"out vec3 frag_color;\n"
"out vec2 vert;\n"
"\n"
"void main()\n"
"{\n"
"    frag_color = color;\n"
"    vert = vertex;\n"
"    gl_Position = vec4(vertex, 0.0, 1.0);\n"
"}";
const char* Simple_frag="#version 400\n"
"\n"
"out vec4 color;\n"
"\n"
"in vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    color = vec4(frag_color, 1.0);\n"
"}";
const char* Simple_vert="#version 400\n"
"\n"
"in vec2 vertex;\n"
"in vec3 color;\n"
"\n"
"out vec3 frag_color;\n"
"\n"
"void main()\n"
"{\n"
"    frag_color = color;\n"
"    gl_Position = vec4(vertex, 0.0, 1.0);\n"
"}";
const char* Uniforms_frag="#version 400\n"
"\n"
"out vec4 color;\n"
"\n"
"uniform float u_time;\n"
"\n"
"void main()\n"
"{\n"
"    color = vec4(abs(sin(u_time)), 0.2f, 0.3, 1.0f);\n"
"}";
