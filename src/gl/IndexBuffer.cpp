#include "IndexBuffer.h"
#include <iostream>

IndexBuffer::IndexBuffer(const void* data, size_t size)
    : m_bufferSize(size)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

const GLuint IndexBuffer::get() const
{
    return m_id;
}

const size_t IndexBuffer::getSize() const
{
    return m_bufferSize;
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::populate(const void* data, size_t size, size_t offset) const
{
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data);
}