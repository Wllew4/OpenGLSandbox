#include "HelloTriangle.h"

#include "gl/glIncludes.h"
#include "gl/init.h"

#include "gl/ShaderProgram.h"
#include "gl/Renderer.h"
#include "gl/VertexArray.h"


void HelloTriangle::run()
{
    //  Spawn window
    GLFWwindow* window = init(640, 480, "Hello Triangle");

    //  Vertex data
    float triangle[] = 
    {
        0.0f,   0.5f,   0.0f,
        0.5f,   -0.5,   0.0f,
        -0.5f,  -0.5f,  0.0f
    };
    
    //  Color data
    float colors[] = {
        1.0f, 1.0f,  0.0f,
        0.0f, 1.0f,  1.0f,
        1.0f, 0.0f,  1.0f
    };

    //  Triangle array
    VertexArray vao;

    //  Vertex buffers
    VertexBuffer vboVertices = VertexBuffer(
        triangle,
        sizeof(triangle),
        0,
        3,
        GL_FLOAT);

    VertexBuffer vboColors = VertexBuffer(
        colors,
        sizeof(colors),
        1,
        3,
        GL_FLOAT);

    vao.bindVertexBuffer(vboVertices);
    vao.bindVertexBuffer(vboColors);

    ShaderProgram shaderProgram;
    shaderProgram.vertexShader("shaders/HelloTriangle.vert");
    shaderProgram.fragmentShader("shaders/HelloTriangle.frag");
    shaderProgram.compile();

    vao.setShader(shaderProgram);

    Renderer r = Renderer(window);
    r.queueVAO(vao);
    r.startRenderLoop();
}