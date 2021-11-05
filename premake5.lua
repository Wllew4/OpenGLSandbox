workspace "OpenGLSandbox"
    configurations { "Release" }

project "Sandbox"
    --Compiler/Linker Options
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    linkoptions { '/NODEFAULTLIB:"LIBCMT"' }
    
    --Files/Directories
    targetdir "bin"
    targetname "sandbox"
    files
    {
        "src/**.cpp",
        "src/**.c",
        "src/**.h"
    }
    includedirs
    {
        "src",
        "lib/glfw/include",
        "lib/glew/include",
        "lib/glm/glm"
    }
    libdirs
    {
        "lib/glfw/lib-vc2019",
        "lib/glew/Win32"
    }
    links
    {
        "glfw3",
        "glew32s",
        "opengl32"
    }

    --Configurations
    filter "configurations:Release"
        defines { "RELEASE" }
        symbols "Off"