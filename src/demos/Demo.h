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
    virtual void update(float deltaTime, std::vector<VertexArray>& objects) = 0;
};