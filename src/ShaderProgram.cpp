#include "ShaderProgram.h"

#include <fstream>
#include <sstream>

GLuint& ShaderProgram::get()
{
    return shader_program;
}

void ShaderProgram::appendShader(const char* file, GLuint type)
{
    const char* source = getFile(file);

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(shader_program, shader);
}

void ShaderProgram::link()
{
    glLinkProgram(shader_program);
}

const char* ShaderProgram::getFile(const char* path)
{
    return (std::stringstream() << std::ifstream(path).rdbuf()).str().c_str();
}