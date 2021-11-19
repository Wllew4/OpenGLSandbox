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

    GLuint vertexShader(const char* file);
    GLuint fragmentShader(const char* file);

public:
    ShaderProgram() {}
    ShaderProgram(const char* vert, const char* frag);
    GLuint get();
    void compile();

    void setAttributeLayout(std::vector<Attribute> attribs)
    {
        attributeLayout = attribs;
    }
};