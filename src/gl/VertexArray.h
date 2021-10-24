#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

class VertexArray
{
private:
    GLuint m_id = 0;
    GLuint m_shader = 0;
    GLuint attribIndex = 0;
    GLuint* indicies;
    GLuint vertexCount;

public:
    VertexArray();

    const GLuint& getId();
    const GLuint& getShader();
    void setShader(ShaderProgram& shader);
    void setIBO(GLuint ibo[], GLuint count);
    GLuint* getIBO();
    const GLuint& getVertexCount();
    void bindVertexBuffer(VertexBuffer& vbo);
};