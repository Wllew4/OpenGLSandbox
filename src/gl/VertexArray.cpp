#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_id);
}

const GLuint& VertexArray::getId()
{
    return m_id;
}

const GLuint& VertexArray::getShader()
{
    return m_shader;
}

void VertexArray::setShader(ShaderProgram& shader)
{
    m_shader = shader.get();
}

void VertexArray::bindVertexBuffer(VertexBuffer& vbo)
{
    glBindVertexArray(m_id);
    vbo.bind(attribIndex);
    attribIndex++;
}


void VertexArray::setIBO(GLuint ibo[], GLuint count)
{
    indicies = ibo;
    vertexCount = count / sizeof(unsigned int);
}

GLuint* VertexArray::getIBO()
{
    return indicies;
}

const GLuint& VertexArray::getVertexCount()
{
    return vertexCount;
}