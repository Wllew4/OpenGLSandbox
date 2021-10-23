#pragma once
#include "Demo.h"

class HelloTriangle : public Demo
{
public:
    HelloTriangle()
        : Demo(640, 480, "Hello Triangle"), renderer(640, 480, "Hello Triangle") {}

    Renderer renderer;

    void run();
    void update(int deltaTime) {}
};