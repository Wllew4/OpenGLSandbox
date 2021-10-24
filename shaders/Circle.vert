#version 400

in vec2 vertex;
in vec3 color;

out vec3 frag_color;
out vec2 vert;

void main()
{
    frag_color = color;
    vert = vertex;
    gl_Position = vec4(vertex, 0.0, 1.0);
}