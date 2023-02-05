# TO LOAD CMAKE PROJECT:
# "/Users/fkavum/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/223.8214.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"
# -DCMAKE_BUILD_TYPE=Debug
# "-DCMAKE_MAKE_PROGRAM=/Users/fkavum/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/223.8214.51/CLion.app/Contents/bin/ninja/mac/ninja"
# -G Ninja -S /Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial0 -B /Users/fkavum/Documents/CPlus/OpenGL/src/Tutorial0/cmake-build-debug

cmake_minimum_required(VERSION 3.24)
project(Project0)
set(CMAKE_CXX_STANDARD 17)

add_executable(Tutorial0 main.cpp)
add_library(Tutorial0_lib STATIC main.cpp)

