#pragma once

#include "Demo.h"

class Uniforms : public Demo
{
public:
    Uniforms()
        : Demo(640, 480, "Uniform color updates") {}

    void run();
    void update(float deltaTime);
};