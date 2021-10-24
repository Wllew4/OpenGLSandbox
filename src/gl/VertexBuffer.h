#pragma once

#include "glIncludes.h"

class VertexBuffer
{
private:
    GLuint m_id;
    
    GLint m_vecSize;
    GLenum m_type;
public:
    VertexBuffer(
        void* data,
        GLsizeiptr length,
        GLint vecSize,
        GLenum type);

    void bind(GLuint index);
};