-- check for vscode premake script and import if available
pcall(require, "vscode")


workspace "OpenGLSandbox"
    configurations { "Debug", "Release" }
    platforms { "Win64" }

project "Sandbox"
    --Compiler/Linker Options
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    linkoptions { '/NODEFAULTLIB:"LIBCMT"' }
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
        "lib/glfw/lib-vc2019",
        "lib/glew/x64",
        "lib/lua-5.4.2_lib64"
    }
    links
    {
        "glfw3",
        "glew32s",
        "opengl32",
        "liblua54"
    }

    --Configurations
    filter "configurations:Debug"
        defines
        {
            "DEBUG"
        }
        symbols "On"

    filter "configurations:Release"
        defines
        {
            "RELEASE"
        }
        symbols "Off"