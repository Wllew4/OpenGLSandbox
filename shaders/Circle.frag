#version 400

out vec4 color;

in vec3 frag_color;
in vec2 vert;

void main()
{
    vec2 origin = vec2(0.0, 0.0);
    float d = sqrt( pow(vert.x-origin.x,2) + pow(vert.y-origin.y,2) );
    float r = 0.5;

    if(d >= r)
    {
        color = vec4(frag_color, 0.0);
    }
    else
    {
        color = vec4(frag_color, 1.0);
    }
}