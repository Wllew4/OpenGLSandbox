#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

class VertexArray
{
private:
    GLuint m_id = 0;
    GLuint m_shader = 0;

public:
    VertexArray();

    const GLuint& getId();
    const GLuint& getShader();
    void setShader(ShaderProgram& shader);
    void bindVertexBuffer(VertexBuffer& vbo);
};