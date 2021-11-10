#pragma once

#include "glIncludes.h"

#include <iostream>

class VertexBuffer
{
private:
    GLuint m_id;
    size_t m_bufferSize;

public:
    VertexBuffer(const void* data, size_t size);
    ~VertexBuffer();

    const GLuint get() const;
    const size_t getSize() const;

    void bind() const;
    void unbind() const;
    
    void populate(const void* data, size_t size, size_t offset) const;
};