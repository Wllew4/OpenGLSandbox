#include "VertexBuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer(const void* data, size_t size)
    : m_bufferSize(size)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_id);
}

const GLuint VertexBuffer::get() const
{
    return m_id;
}

const size_t VertexBuffer::getSize() const
{
    return m_bufferSize;
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::populate(const void* data, size_t size, size_t offset) const
{
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}