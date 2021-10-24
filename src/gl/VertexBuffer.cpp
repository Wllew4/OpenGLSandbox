#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(
    void* data,
    GLsizeiptr length,
    GLint vecSize,
    GLenum type)
    : m_vecSize(vecSize), m_type(type)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW);
}

void VertexBuffer::bind(GLuint index)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glVertexAttribPointer(index, m_vecSize, m_type, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(index);
}