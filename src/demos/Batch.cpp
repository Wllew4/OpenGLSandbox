#include "Batch.h"

#include "gl/glIncludes.h"
#include "gl/shaders.h"

#include "gl/Renderer.h"
#include "gl/VertexArray.h"
#include "gl/ShaderProgram.h"

#include <iostream>
#include <iterator>

struct Mesh
{
    unsigned int vertexCount;
    float vertices[9];
    unsigned int indexCount;
    unsigned int indices[3];
};

void Batch::run()
{
    Mesh meshes[] =
    {
        {
            3,
            {
                -1.0f, -1.0f, 0.0f,
                -1.0f,  0.0f, 0.0f,
                0.0f, -1.0f, 0.0f,
            },
            3,
            {
                0, 1, 2
            }
        },
        {
            3,
            {
                1.0f,  1.0f, 0.0f,
                1.0f,  0.0f, 0.0f,
                0.0f,  1.0f, 0.0f,
            },
            3,
            {
                0, 1, 2
            }
        }
    };

    float vertices[18] = {};
    unsigned int indices[6] = {};

    for(int i = 0; i < 2; i++)
    {
        std::copy(std::begin(meshes[i].vertices), std::end(meshes[i].vertices), std::begin(vertices) + i * 3 * meshes[i].vertexCount);
        for(int j = 0; j < 3; j++)
        {
            meshes[i].indices[j] += meshes[i].indexCount * i;
        }
        std::copy(std::begin(meshes[i].indices), std::end(meshes[i].indices), std::begin(indices) + i * meshes[i].vertexCount);
    }

    VertexArray vao;

    VertexBuffer vbo = VertexBuffer
    (
        nullptr,
        1024,
        3,
        GL_FLOAT
    );

    vao.bindVertexBuffer(vbo);
    vao.setIBO(indices, sizeof(indices));

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    //  Shader construction
    ShaderProgram shaderProgram = ShaderProgram(Batch_vert, Batch_frag);
    shaderProgram.compile();

    //  Applying shader to VAO
    vao.setShader(shaderProgram);

    //  Render
    renderer.queueVAO(vao);

    renderer.startRenderLoop();
}