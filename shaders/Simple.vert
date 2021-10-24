#version 400

in vec2 vertex;
in vec3 color;

out vec3 frag_color;

void main()
{
    frag_color = color;
    gl_Position = vec4(vertex, 0.0, 1.0);
}