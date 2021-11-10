#pragma once

#include "glIncludes.h"
#include <string>
#include <vector>

struct Attribute
{
    GLuint count;
    GLenum type;
    std::string name;
};

class ShaderProgram
{
private:
    GLuint program = glCreateProgram();
    std::vector<Attribute> attributeLayout;

public:
    ShaderProgram() {}
    ShaderProgram(const char* vert, const char* frag);
    GLuint get();

    GLuint vertexShader(const char* file);
    GLuint fragmentShader(const char* file);
    void compile();


};