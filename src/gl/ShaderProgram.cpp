#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vert, const char* frag)
{
    vertexShader(vert);
    fragmentShader(frag);
    compile();
}

GLuint ShaderProgram::get()
{
    return program;
}

GLuint ShaderProgram::vertexShader(const char* source)
{
    GLuint shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);

    return shader;
}

GLuint ShaderProgram::fragmentShader(const char* source)
{
    GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glAttachShader(program, shader);

    return shader;
}

void ShaderProgram::compile()
{
    glLinkProgram(program);
}