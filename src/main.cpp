#include <iostream>

#include <glIncludes.h>
#include <init.h>
#include "voGenerator.h"

int main()
{
    GLFWwindow* window = init(640, 480, "OpenGL Sandbox");

    float triangle[] = 
    {
        0.0f,   0.5f,   0.0f,
        0.5f,   -0.5,   0.0f,
        -0.5f,  -0.5f,  0.0f
    };
    
    float colors[] = {
        1.0f, 1.0f,  0.0f,
        0.0f, 1.0f,  1.0f,
        1.0f, 0.0f,  1.0f
    };

    GLuint vbo = vertexBuffer(triangle, sizeof(triangle));
    GLuint vbo_colors = vertexBuffer(colors, sizeof(colors));

    GLuint vao = vertexArray();
    bindVBOtoVAO(vao, vbo, 0);
    bindVBOtoVAO(vao, vbo_colors, 1);

    GLuint shaderProgram = glCreateProgram();
    appendShader(shaderProgram, "shaders/test.vert", GL_VERTEX_SHADER);
    appendShader(shaderProgram, "shaders/test.frag", GL_FRAGMENT_SHADER);

    glBindAttribLocation(shaderProgram, 0, "vp");
    glBindAttribLocation(shaderProgram, 1, "frag_color");
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vao);

        int location = glGetUniformLocation(shaderProgram, "u_color");
        glUniform4f(location, 0.5f, 0.2f, 0.3f, 1.0f);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}