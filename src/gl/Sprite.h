#pragma once

#include "glIncludes.h"
#include "VertexBuffer.h"
#include "Material.h"
#include <vec2.hpp>

class Sprite
{
private:
    std::vector<glm::vec2> vertices;
    std::vector<glm::uint> indices;
    VertexBuffer vbo;
    GLuint vao;
    Material& material;

public:
    Sprite(std::vector<glm::vec2> vertices, std::vector<glm::uint> indices, Material& mat)
        : vertices(vertices), indices(indices), material(mat), vbo(vertices.data(), vertices.size() * sizeof(glm::vec2))
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        vbo.bind();

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glEnableVertexAttribArray(0);
    }

    const size_t getVertexCount()
    {
        return vertices.size();
    }

    const GLuint* getIndices()
    {
        return indices.data();
    }

    Material& getMaterial()
    {
        return material;
    }

    const GLuint& getVAO()
    {
        return vao;
    }

    const GLuint getVBO()
    {
        return vbo.get();
    }
};