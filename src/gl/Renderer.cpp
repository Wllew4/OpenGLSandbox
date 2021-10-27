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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
}

std::vector<VertexArray>& Renderer::getQueue()
{
    return queue;
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
        
        //  Calculate elapsed time
        std::chrono::duration<float> elapsedTime = std::chrono::steady_clock::now() - lastTimestamp;
        float delta = (float)std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();
        lastTimestamp = std::chrono::steady_clock::now();
        
        demo.update(delta);

        //  Update
        for(VertexArray& vao : queue)
        {
            glBindVertexArray(vao.getId());
            glUseProgram(vao.getShader());
            glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, vao.getIBO());
        }

        

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}