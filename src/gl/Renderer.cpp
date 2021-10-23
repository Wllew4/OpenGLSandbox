#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height, const char* title)
{
    if(!glfwInit())
    {
        std::cerr << "ERROR: Failed to initialize GLFW\n" << std::endl;
        exit(1);
    }
    glewExperimental = GL_TRUE;

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3\n";
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glewInit();
    
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
}

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

        // std::chrono::duration<double> elapsedTime = std::chrono::steady_clock::now() - lastTimestamp;

        // demo.update();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}