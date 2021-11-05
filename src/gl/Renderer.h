#pragma once

#include "glIncludes.h"
#include "Sprite.h"
#include <vector>
#include <chrono>

//  forward declaration
class Demo;

class Renderer
{
private:
    std::vector<Sprite> queue;
    GLFWwindow* window;
    Demo& demo;
    std::chrono::time_point<std::chrono::steady_clock> lastTimestamp = std::chrono::steady_clock::now();
    
public:
    Renderer(int width, int height, const char* title, Demo& demo);

    std::vector<Sprite>& getQueue();
    void queueVAO(Sprite vao);
    void startRenderLoop();
};