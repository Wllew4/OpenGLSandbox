#pragma once

#include "Demo.h"

#include "gl/Sprite.h"

class NewRenderer : public Demo
{
public:
    NewRenderer()
        : Demo(920, 540, "New renderer woop woop") {}

    void run();
    void update(float deltaTime);
};