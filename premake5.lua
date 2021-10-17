workspace "WorkspaceName"
    configurations { "Debug", "Release" }

project "ProjectName"
    --Compiler/Linker Options
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    --Files/Directories
    targetdir "bin"
    targetname "out"
    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    includedirs
    {
        "src"
    }
    libdirs
    {
        
    }
    links
    {
        
    }

    --Configurations
    filter "configurations:Release"
        defines { "RELEASE" }
        symbols "Off"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "Off"