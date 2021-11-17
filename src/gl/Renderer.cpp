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

void Renderer::queueSprite(Sprite* sprite)
{
    queue.emplace_back(
        sprite->getVertices().data(), sprite->getVertices().size() * sizeof(glm::vec2),
        sprite->getIndices().data(), sprite->getIndices().size() * sizeof(GLuint),
        sprite->getMaterial(),
        sprite->getVertexCount(),
        sprite->getIndices()
    );

    const size_t i = queue.size() - 1;
    queue[i].vao.bind();
    queue[i].vbo.bind();
    queue[i].vao.setAttributeLayout(s_SpriteAttributeLayout);
    glBindAttribLocation(queue[i].material.getShader(), 0, "a_vertex");
}

void Renderer::startRenderLoop()
{
    while(!glfwWindowShouldClose(window))
    {
        //  Clear frame buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //  Calculate elapsed time
        std::chrono::duration<float> elapsedTime = std::chrono::steady_clock::now() - lastTimestamp;
        float delta = (float)std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count();
        lastTimestamp = std::chrono::steady_clock::now();
        
        demo.update(delta);

        //  Draw
        for(Batch& batch : queue)
        {
            batch.vao.bind();
            batch.vbo.bind();
            batch.ibo.bind();
            glUseProgram(batch.material.getShader());
            glDrawElements(GL_TRIANGLES, batch.vertexCount, GL_UNSIGNED_INT, nullptr);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
}