/*
Previously: we set up OpenGL windowing and context library called GLFW
which initialize a graphics context for OpenGL

 Windows has graphics api called directX, OpenGL its not operating system related, its upto GPU manufacturers.
 Since we are on windows, we need to actually get all of the modern OpenGL functions, we need to get them from somewhere,
 OpenGL functions are implemented in you GPU drivers, so what we need to do, for any functionality newer than OpenGL 1.1,
 get into drivers and pull out the functions. Which means, get the function declerations and then link against functions.

 We need access to driver DLL files and just retreve function pointers to the functions inside those libraries.

so for OpenGL if we want to do this manually, it wont be crssplatform, to access the drivers and pull out functions from that we need to use win32 api calls etc.
 loading library and loading function points all that, second problem we need to go thought all the opengl functions and implement it...


We have simply library for this! : GLEW

all it does, it provides the OpenGL Api specification, kind of function declarations and symbol declarations, and contants and all that stuff
 for you in a header file and then the behind the scenes file (cpp) file the actual implementation of the library identifies what graphic drivers
 youre using, finds the appropriate DLL file and then loads all the function pointers.

 They dont implement the functions or anything they  just access functions that are already on you computer.


 */