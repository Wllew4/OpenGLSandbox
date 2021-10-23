#pragma once

#include "gl/Renderer.h"

class Demo
{
protected:
    Demo(int width, int height, const char* title) {}
        // : renderer(width, height, title) {}

public:
    // Renderer renderer;
    virtual void run() = 0;
    virtual void update(int deltaTime) = 0;
};