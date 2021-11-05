#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(
    GLint vecSize,
    GLenum type)
    : m_vecSize(vecSize), m_type(type)
{
    glGenBuffers(1, &m_id);
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::bind(GLuint index)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
    glVertexAttribPointer(index, m_vecSize, m_type, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(index);
}

void VertexBuffer::populate(std::vector<float> data)
{
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);
}