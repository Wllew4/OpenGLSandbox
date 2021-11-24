dofile("./lua/getfile.lua")

local sprite =
{
    vertices =
    {
        0.5,  -0.5,
        -0.5, -0.5,
        0.0,  0.5
    },

    indices =
    {
        0, 1, 2
    }
}

loadMesh2D(sprite)

local shader =
{
    getfile("shaders/Standard.vert"),
    getfile("shaders/Standard.frag")
}

loadShader(shader)