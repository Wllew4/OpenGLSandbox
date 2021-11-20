#include "Sandboxing/Sandbox.h"

int main(int argc, char** argv)
{
    Sandbox s = Sandbox();
    s.run("sandbox/sandbox.lua");
    return 0;
}