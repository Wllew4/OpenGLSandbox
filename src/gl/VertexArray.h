#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include <vector>

class VertexArray
{
private:
    GLuint m_id = 0;

public:
    VertexArray();
    ~VertexArray();
    const GLuint get();

    void bind() const;

    void unbind() const;

    void setAttributeLayout(std::vector<Attribute> attributeLayout) const;
};