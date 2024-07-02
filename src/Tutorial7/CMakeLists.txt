cmake_minimum_required(VERSION 3.24)
project(OpenGL)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

add_executable(OpenGL ./src/Application.cpp)
set(CMAKE_VERBOSE_MAKEFILE ON)

target_include_directories(OpenGL PUBLIC ./../../dependencies/GLFW/include)
find_library(GLFWLib libglfw3.a ./../../dependencies/GLFW/lib-universal/)
target_link_libraries(OpenGL LINK_PUBLIC ${GLFWLib})

target_include_directories(OpenGL PUBLIC ./../../dependencies/GLEW/include)
find_library(GLEWLib libGLEW.a ./../../dependencies/GLEW/lib)
target_link_libraries(OpenGL LINK_PUBLIC ${GLEWLib})

#target_compile_definitions(OpenGL PUBLIC GLEW_STATIC)