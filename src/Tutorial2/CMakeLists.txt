cmake_minimum_required(VERSION 3.24)
project(OpenGL)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

add_executable(OpenGL ./src/Application.cpp)
set(CMAKE_VERBOSE_MAKEFILE ON)

target_include_directories(OpenGL PUBLIC ./../../dependencies/GLFW/include)
find_library(GLFWLib libglfw3.a ./../../dependencies/GLFW/lib-universal/)
target_link_libraries(OpenGL LINK_PUBLIC ${GLFWLib})

#set( OF_DIRECTORY_BY_USER ./GLFW/lib-universal )
#list(APPEND CMAKE_MODULE_PATH ./GLFW/lib-universal)
#list(APPEND CMAKE_MODULE_PATH /Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial2/GLFW/lib-universal)
#include(/Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial2/GLFW/lib-universal)
#find_path(Path PATH_SUFFIXES "GLFW")
#find_library(GLFWLib libglfw3 /Users/fkavum/Documents/CPlus/OpenGL/dependencies/GLFW/lib-universal/)
#set(CMAKE_PREFIX_PATH "/Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial2")
#link_directories("/Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial2")
#find_library(GLFWLib NAMES libglfw3 HINTS /Users/fkavum/Documents/CPlus/OpenGL/dependencies/GLFW/lib-universal/)


#WORKING
#find_path(MY_INCLUDE_DIR NAMES libglfw3.a PATHS "/Users/fkavum/Documents/CPlus/OpenGL/dependencies/GLFW/lib-universal/")
#message(STATUS "MY_INCLUDE_DIR: ${MY_INCLUDE_DIR}")

#ANOTHER WORKING
#find_path(MY_INCLUDE_DIR NAMES libglfw3.a PATHS "./../../dependencies/GLFW/lib-arm64/")
#message(STATUS "MY_INCLUDE_DIR: ${MY_INCLUDE_DIR}")