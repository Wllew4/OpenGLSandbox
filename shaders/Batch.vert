#version 400

in vec3 vertex;

out vec3 frag_color;

void main()
{
    frag_color = vertex;
    gl_Position = vec4(vertex, 1.0);
}