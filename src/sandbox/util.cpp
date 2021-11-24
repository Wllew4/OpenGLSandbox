#include "util.h"

#include <fstream>

std::string loadFile(std::string path)
{
    return std::string(
        std::istreambuf_iterator<char>(std::ifstream(path).rdbuf()),
        std::istreambuf_iterator<char>());
}