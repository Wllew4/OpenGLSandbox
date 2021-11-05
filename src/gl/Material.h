#pragma once

#include "glIncludes.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include <vector>

class Material
{
private:
    ShaderProgram& shader;
    VertexBuffer color = VertexBuffer(3, GL_FLOAT);

public:
    Material(ShaderProgram& _shader)
        : shader(_shader)
    {

    }

    GLuint getColorBuffer()
    {
        return color.getID();
    }

    const GLuint& getShader()
    {
        return shader.get();
    }
};