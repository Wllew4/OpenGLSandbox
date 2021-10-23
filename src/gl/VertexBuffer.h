#pragma once

#include "glIncludes.h"

class VertexBuffer
{
private:
    GLuint m_id;
    
    GLuint m_index;
    GLint m_vecSize;
    GLenum m_type;
public:
    VertexBuffer(
        float data[],
        GLsizeiptr length,
        GLuint index,
        GLint vecSize,
        GLenum type);

    void bind();
};