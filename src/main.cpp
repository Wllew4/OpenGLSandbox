#include "sandbox/Sandbox.h"

int main(int argc, char** argv)
{
    Sandbox s = Sandbox(argv[0]);
    s.run("sandbox/sandbox.lua");
    return 0;
}