-- check for vscode premake script and import if available
pcall(require, "vscode")


workspace "OpenGLSandbox"
    configurations { "Release" }
    platforms { "Win64" }

project "Sandbox"
    --Compiler/Linker Options
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    linkoptions
    {
        '/NODEFAULTLIB:"LIBCMT"'
    }
    prebuildcommands
    {
        "python scripts/copy_resources.py"
    }
    
    --Files/Directories
    targetdir "bin"
    targetname "sandbox"
    files
    {
        "src/**.cpp"
    }
    includedirs
    {
        "src",
        "lib/glfw/include",
        "lib/glew/include",
        "lib/glm/glm",
        "lib/lua-5.4.2_lib64/include"
    }
    libdirs
    {
        "lib/glfw/src/Release",
        "lib/glew/lib/Release"
    }
    links
    {
        "glfw3",
        "glew",
        "opengl32"
    }

    --Configurations
    filter "configurations:Release"
        defines
        {
            "RELEASE"
        }
        symbols "Off"