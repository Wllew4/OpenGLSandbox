#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "Material.h"
#include <vec2.hpp>
#include <iostream>

class Sprite
{
private:
    std::vector<glm::vec2> vertices;
    std::vector<GLuint> indices;
    VertexBuffer vbo = VertexBuffer(vertices.data(), vertices.size() * sizeof(glm::vec2));
    GLuint vao;
    Material& material;

public:
    Sprite(const std::vector<glm::vec2>& vertices, const std::vector<GLuint>& indices, Material& mat)
        : vertices(vertices), indices(indices), material(mat)
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

    const size_t getVertexCount()
    {
        return vertices.size() * 2;
    }

    const GLuint* getIndices()
    {
        return indices.data();
    }

    Material getMaterial()
    {
        return material;
    }

    const GLuint getVAO()
    {
        return vao;
    }

    const GLuint getVBO()
    {
        return vbo.get();
    }
};