#include "HelloTriangle.h"

#include "gl/glIncludes.h"
#include "gl/shaders.h"

#include "gl/Renderer.h"
#include "gl/VertexArray.h"
#include "gl/ShaderProgram.h"

void HelloTriangle::run()
{
    //  Vertex data
    float triangle[] = 
    {
        0.0f,   0.5f,
        0.5f,   -0.5,
        -0.5f,  -0.5f,
    };

    //  Indices
    unsigned int indices[] =
    {
        0, 1, 2
    };
    
    //  Color data
    float colors[] = {
        1.0f, 1.0f,  0.0f,
        0.0f, 1.0f,  1.0f,
        1.0f, 0.0f,  1.0f
    };

    //  Triangle array
    VertexArray vao;

    //  Vertex buffer
    VertexBuffer vboVertices = VertexBuffer
    (
        triangle,
        sizeof(triangle),
        2,
        GL_FLOAT
    );

    //  Color buffer
    VertexBuffer vboColors = VertexBuffer
    (
        colors,
        sizeof(colors),
        3,
        GL_FLOAT
    );

    //  Binding VBOs to VAO
    vao.bindVertexBuffer(vboVertices);
    vao.setIBO(indices, sizeof(indices));
    vao.bindVertexBuffer(vboColors);

    //  Shader construction
    ShaderProgram shaderProgram;
    shaderProgram.vertexShader(Simple_vert);
    shaderProgram.fragmentShader(Simple_frag);
    shaderProgram.compile();

    //  Applying shader to VAO
    vao.setShader(shaderProgram);

    //  Render
    renderer.queueVAO(vao);
    renderer.startRenderLoop();
}