#pragma once
#include "Demo.h"

class HelloTriangle : public Demo
{
public:
    HelloTriangle()
        : Demo(640, 480, "Hello Triangle") {}

    void run();
    void update(float deltaTime) {}
};