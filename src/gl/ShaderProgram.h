#pragma once

#include "glIncludes.h"

#define VERTEX_BUFFER_INDEX 0
#define VERTEX_BUFFER_NAME  "vertex"
#define COLOR_BUFFER_INDEX  1
#define COLOR_BUFFER_NAME   "color"

class ShaderProgram
{
private:
    GLuint program = glCreateProgram();
public:
    GLuint get();
    GLuint vertexShader(const char* file);
    GLuint fragmentShader(const char* file);
    void compile();
};