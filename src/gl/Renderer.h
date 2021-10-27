#pragma once

#include "glIncludes.h"
#include "VertexArray.h"
#include <vector>
#include <chrono>

//  forward declaration
class Demo;

class Renderer
{
private:
    std::vector<VertexArray> queue;
    GLFWwindow* window;
    Demo& demo;
    std::chrono::time_point<std::chrono::steady_clock> lastTimestamp = std::chrono::steady_clock::now();
    
public:
    Renderer(int width, int height, const char* title, Demo& demo);

    std::vector<VertexArray>& getQueue();
    void queueVAO(VertexArray vao);
    void startRenderLoop();
};