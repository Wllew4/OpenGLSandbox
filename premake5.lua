-- check for vscode premake script and import if available
pcall(require, "vscode")


workspace "OpenGLSandbox"
    configurations { "Release" }
    platforms { "Win32" }

project "Sandbox"
    --Compiler/Linker Options
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    linkoptions { '/NODEFAULTLIB:"LIBCMT"' }
    postbuildcommands
    {
        "python scripts/copy_resources.py"
    }
    
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
        "shaders",
        "lib/glfw/include",
        "lib/glew/include",
        "lib/glm/glm",
        "lib/lua-5.4.2_lib32/include"
    }
    libdirs
    {
        "lib/glfw/lib-vc2019",
        "lib/glew/Win32",
        "lib/lua-5.4.2_lib32"
    }
    links
    {
        "glfw3",
        "glew32s",
        "opengl32",
        "liblua54"
    }

    --Configurations
    filter "configurations:Release"
        defines
        {
            "RELEASE"
        }
        symbols "Off"