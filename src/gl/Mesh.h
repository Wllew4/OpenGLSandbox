#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "Material.h"

class Mesh
{
private:
    size_t vertexCount;
    GLuint* indices;
    GLuint vbo;
    GLuint vao;
    Material& material;

public:
    Mesh(void* data, GLuint size, GLuint* indices, Material& mat)
        : indices(indices), vertexCount(size), material(mat)
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        // glBindBuffer(GL_ARRAY_BUFFER, material.getColorBuffer());
        // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glEnableVertexAttribArray(0);
        // glEnableVertexAttribArray(1);
    }

    const size_t& getVertexCount()
    {
        return vertexCount;
    }

    const GLuint* getIndices()
    {
        return indices;
    }

    Material& getMaterial()
    {
        return material;
    }

    const GLuint& getVAO()
    {
        return vao;
    }

    const GLuint* getIBO()
    {
        return indices;
    }

    const GLuint& getVBO()
    {
        return vbo;
    }
};