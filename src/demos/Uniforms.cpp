#include "Uniforms.h"

#include "gl/glIncludes.h"
#include "gl/shaders.h"

#include "gl/Renderer.h"
#include "gl/VertexArray.h"
#include "gl/ShaderProgram.h"

void Uniforms::update(float deltaTime, std::vector<VertexArray>& objects)
{
    static float elapsedTime;
    elapsedTime += deltaTime / 1000;
    glUseProgram(objects[0].getShader());
    int location = glGetUniformLocation(objects[0].getShader(), "u_time");
    glUniform1f(location, elapsedTime);
}

void Uniforms::run()
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
    shaderProgram.vertexShader(Simple_vert);
    shaderProgram.fragmentShader(Uniforms_frag);
    shaderProgram.compile();

    //  Applying shader to VAO
    vao.setShader(shaderProgram);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //  Render
    renderer.queueVAO(vao);
    renderer.startRenderLoop();
}