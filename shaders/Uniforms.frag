#version 400

out vec4 color;

uniform float u_time;

void main()
{
    color = vec4(abs(sin(u_time)), 0.2f, 0.3, 1.0f);
}