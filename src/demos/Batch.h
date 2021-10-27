#pragma once

#include "Demo.h"

class Batch : public Demo
{
public:
    Batch()
        : Demo(640, 480, "Batch rendering") {}

    void run();
    void update(float deltaTime) {}
};