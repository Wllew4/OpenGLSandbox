#include "demos/Demo.h"
#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height, const char* title, Demo& demo)
    : demo(demo)
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
    
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
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

        //  Calculate elapsed time
        std::chrono::duration<double> elapsedTime = std::chrono::steady_clock::now() - lastTimestamp;
        uint64_t delta = std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();
        lastTimestamp = std::chrono::steady_clock::now();
        //  Update
        demo.update(delta);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}