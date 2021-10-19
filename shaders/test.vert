#version 400

layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 frag_color;

out vec3 color;

void main()
{
    color = frag_color;
    gl_Position = vec4(vp, 1.0);
}