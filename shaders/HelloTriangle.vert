#version 400

in vec3 vertex;
in vec3 color;

out vec3 frag_color;

void main()
{
    frag_color = color;
    gl_Position = vec4(vertex, 1.0);
}