#pragma once

#include "glIncludes.h"
#include "Sprite.h"
#include <vector>
#include <chrono>

//  forward declaration
class Demo;

struct Batch
{
    VertexArray vao;
    VertexBuffer vbo;
    Material& material;
    size_t vertexCount;
    const GLuint* indices;
    
    Batch(
        const void* data, size_t size,
        Material& material,
        size_t vertexCount,
        const GLuint* indices)
        : vao(), vbo(data, size), material(material), vertexCount(vertexCount), indices(indices) {}
};

class Renderer
{
private:
    std::vector<Batch> queue;
    GLFWwindow* window;
    Demo& demo;
    std::chrono::time_point<std::chrono::steady_clock> lastTimestamp = std::chrono::steady_clock::now();
    
public:
    Renderer(int width, int height, const char* title, Demo& demo);

    void queueSprite(Sprite* sprite);
    void startRenderLoop();
};