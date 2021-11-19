#pragma once

#include "glIncludes.h"
#include "Sprite.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <vector>
#include <chrono>

//  forward declaration
class Demo;

struct Batch
{
    VertexArray vao;
    VertexBuffer vbo;
    IndexBuffer ibo;
    Material& material;
    size_t vertexCount;
    
    Batch(
        const void* data, size_t size,
        const void* i_data, size_t i_size,
        Material& material,
        size_t vertexCount)
        : vao(), vbo(data, size), ibo(i_data, i_size), material(material), vertexCount(vertexCount) {}
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