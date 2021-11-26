#pragma once

#include "glIncludes.h"
#include "Material.h"
#include <vec2.hpp>
#include <iostream>

static std::vector<Attribute> s_SpriteAttributeLayout =
{
    { 2, GL_FLOAT, "a_vertex" }
};

class Mesh2D
{
private:
    std::vector<glm::vec2> vertices;
    std::vector<GLuint> indices;

public:
    Mesh2D(const std::vector<glm::vec2>& vertices, const std::vector<GLuint>& indices)
        : vertices(vertices), indices(indices) {}

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
};