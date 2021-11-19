#pragma once

#include "glIncludes.h"
#include "Material.h"
#include <vec2.hpp>
#include <iostream>

static std::vector<Attribute> s_SpriteAttributeLayout =
{
    { 2, GL_FLOAT, "a_vertex" }
};

class Sprite
{
private:
    std::vector<glm::vec2> vertices;
    std::vector<GLuint> indices;
    Material& material;

public:
    Sprite(const std::vector<glm::vec2>& vertices, const std::vector<GLuint>& indices, Material& mat)
        : vertices(vertices), indices(indices), material(mat) {}

    const std::vector<glm::vec2> getVertices()
    {
        return vertices;
    }

    const size_t getVertexCount()
    {
        return vertices.size() * 2;
    }

    const std::vector<GLuint> getIndices()
    {
        return indices;
    }

    Material& getMaterial()
    {
        return material;
    }
};