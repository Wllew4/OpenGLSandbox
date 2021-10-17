# premake-vscode-quickstart
This template is used as a quickstart for using Visual Studio Code with premake for Visual Studio or GNU Make. It includes helpful scripts to sync premake configuration settings such as include paths with VSCode configurations for C/C++.

Anyone is welcome to use this template for their own premake/vscode projects!

# About
## Prerequisites:
* Visual Studio Code
* Either Visual Studio or GNU Make (MinGW works for Windows)
* Python 3.9 (untested on older versions)

Supported build systems:
* Visual Studio
* GNU Make or MinGW


# Getting Started
## Step 1: Use template
Make a new repository from this template on GitHub.

## Step 2: Configure `premake5.lua`
`premake5.lua` comes preconfigured with typical project settings. You may want
to change:
* `workspace` - Name of Solution
* `project` - Name of Project
* `cdialect` - version of C to use
* `cppdialect` - Version of C++ to use
* `targetname` - The name of the generated .exe file

Read more about configuring Premake [here](https://premake.github.io/docs/).

## Step 3: Configure `scripts/CONFIG.py`
* Change `BUILD_SYSTEM` to match your build system of choice
    * Options are `vs2019` and `gmake2`
* If using GNU Make, change `MAKE_BINARY` to match the name of your make executable
    * For many, this will just be `make`. MinGW users will likely have 
    `mingw32-make`. Make sure this executable is added to your PATH on Windows.
* Visual Studio users must ensure that `msbuild` is added to their PATH.

## Step 4: Generate build files and configuration
Run `python scripts/premake.py` from the command line in the root of the project. This will generate build files and initialize `.vscode/c_cpp_properties.json`.

# Usage
The repository comes with several additional helpful scripts.
## Build code
`python scripts/build.py`
## Run code
`python scripts/run.py`
## Build & run
`python scripts/build_and_run.py`
## Regenerate build files
`python scripts/premake.py`