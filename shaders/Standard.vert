#version 400

layout(location = 0) in vec2 a_vertex;

out vec3 frag_color;

void main()
{
    frag_color = vec3(1.0, gl_VertexID/2.0, 1.0);
    gl_Position = vec4(a_vertex, 0.0, 1.0);
}