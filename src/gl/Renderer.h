#pragma once

#include "glIncludes.h"
#include "Mesh.h"
#include <vector>
#include <chrono>

//  forward declaration
class Demo;

class Renderer
{
private:
    std::vector<Mesh> queue;
    GLFWwindow* window;
    Demo& demo;
    std::chrono::time_point<std::chrono::steady_clock> lastTimestamp = std::chrono::steady_clock::now();
    
public:
    Renderer(int width, int height, const char* title, Demo& demo);

    std::vector<Mesh>& getQueue();
    void queueVAO(Mesh vao);
    void startRenderLoop();
};