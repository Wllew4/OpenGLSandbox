#pragma once

#include "Demo.h"

class IndexedSquare : public Demo
{
public:
    IndexedSquare()
        : Demo(640, 480, "Hello Square") {}

    void run();
    void update(float deltaTime, std::vector<VertexArray>& objects) {}
};