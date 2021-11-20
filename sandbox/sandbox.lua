function GetFile(path)
    local f = assert(io.open(path, "rb"))
    local content = f:read("*all")
    f:close()
    return content
end

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

getHello(sprite)