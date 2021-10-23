#pragma once

#include "glIncludes.h"
#include "VertexArray.h"
// #include "demos/Demo.h"
#include <vector>
#include <chrono>

class Renderer
{
private:
    std::vector<VertexArray> queue;
    GLFWwindow* window;
    // std::chrono::time_point<std::chrono::steady_clock> lastTimestamp = std::chrono::steady_clock::now();

    // Demo& demo;
    
public:
    Renderer(int width, int height, const char* title);

    void queueVAO(VertexArray vao);
    void startRenderLoop();
};