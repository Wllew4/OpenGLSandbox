#pragma once

#include "gl/Renderer.h"

class Demo
{
protected:
    Demo(int width, int height, const char* title)
        : renderer(width, height, title, *this) {}

    Renderer renderer;

public:
    virtual void run() = 0;
    virtual void update(uint64_t deltaTime) = 0;
};