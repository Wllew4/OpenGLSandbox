#pragma once

#include "glIncludes.h"
#include <vector>

class VertexBuffer
{
private:
    GLuint m_id;
    
    GLint m_vecSize;
    GLenum m_type;

public:
    VertexBuffer(
        GLint vecSize,
        GLenum type);

    GLuint getID()
    {
        return m_id;
    }

    void bind(GLuint index);
    
    void populate(std::vector<float> data);
};