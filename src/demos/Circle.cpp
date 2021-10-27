#include "Circle.h"

#include "gl/glIncludes.h"
#include "gl/shaders.h"

#include "gl/Renderer.h"
#include "gl/VertexArray.h"
#include "gl/ShaderProgram.h"

void Circle::run()
{
    float vertices[] = 
    {
        -.5f, -.5f,
        .5f,  -.5f,
        .5f,  .5f,
        -.5f, .5f
    };

    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    //  Color data
    float colors[] = {
        1.0f,  1.0f,  0.0f,
        0.0f,  1.0f,  1.0f,
        1.0f,  0.0f,  1.0f,
        1.0f,  1.0f,  0.0f
    };

    VertexArray vao;

    VertexBuffer vboVert = VertexBuffer
    (
        vertices,
        sizeof(vertices),
        2,
        GL_FLOAT
    );

    VertexBuffer vboColors = VertexBuffer
    (
        colors,
        sizeof(colors),
        3,
        GL_FLOAT
    );

    vao.bindVertexBuffer(vboVert);
    vao.setIBO(indices, sizeof(indices));
    vao.bindVertexBuffer(vboColors);

    //  Shader construction
    ShaderProgram shaderProgram;
    shaderProgram.vertexShader(Circle_vert);
    shaderProgram.fragmentShader(Circle_frag);
    shaderProgram.compile();

    //  Applying shader to VAO
    vao.setShader(shaderProgram);

    //  Render
    renderer.queueVAO(vao);

    renderer.startRenderLoop();
}