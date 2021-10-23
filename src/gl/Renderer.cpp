#include "Renderer.h"

Renderer::Renderer(GLFWwindow* window)
    : window(window) {}

void Renderer::queueVAO(VertexArray vao)
{
    queue.emplace_back(vao);
}

void Renderer::startRenderLoop()
{
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        for(VertexArray vao : queue)
        {
            glBindVertexArray(vao.getId());
            glUseProgram(vao.getShader());
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}