#pragma once

#include "Demo.h"

class Circle : public Demo
{
public:
    Circle()
        : Demo(640, 480, "Circle!!") {}

    void run();
    void update(uint64_t deltaTime) {}
};