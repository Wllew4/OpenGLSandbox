#pragma once

#include "glIncludes.h"

#include <iostream>

class IndexBuffer
{
private:
    GLuint m_id;
    size_t m_bufferSize;

public:
    IndexBuffer(const void* data, size_t size);
    ~IndexBuffer();

    const GLuint get() const;
    const size_t getSize() const;

    void bind() const;
    void unbind() const;
    
    void populate(const void* data, size_t size, size_t offset) const;
};