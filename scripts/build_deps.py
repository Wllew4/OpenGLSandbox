import os

os.system('cmake -S lib/glfw -B lib/glfw -D GLFW_BUILD_EXAMPLES=OFF -D GLFW_BUILD_TESTS=OFF -D GLFW_BUILD_DOCS=OFF')
os.system('cmake --build lib/glfw --config Release')
os.system('cmake -S lib/glew -B lib/glew')
os.system('cmake --build lib/glew --config Release --target libglew_static')