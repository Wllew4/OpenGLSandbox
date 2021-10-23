#include "VertexBuffer.h"

#include <iostream>

VertexBuffer::VertexBuffer(
    float data[],
    GLsizeiptr length,
    GLuint index,
    GLint vecSize,
    GLenum type)
    : m_index(index), m_vecSize(vecSize), m_type(type)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
}

void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glVertexAttribPointer(m_index, m_vecSize, m_type, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(m_index);
}