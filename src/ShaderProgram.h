#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderProgram
{
public:
    GLuint& get();
    void appendShader(const char* file, GLuint type);
    void link();

private:
    GLuint shader_program = glCreateProgram();
    static const char* getFile(const char* path);

};