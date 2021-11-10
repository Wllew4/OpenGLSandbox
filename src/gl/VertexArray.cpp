#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_id);
}

const GLuint VertexArray::get()
{
    return m_id;
}

void VertexArray::bind() const
{
    glBindVertexArray(m_id);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::setAttributeLayout(std::vector<Attribute> attributeLayout) const
{
    bind();
    for (size_t i = 0; i < attributeLayout.size(); i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attributeLayout[i].count, attributeLayout[i].type, GL_FALSE, 0, 0);
    }
}