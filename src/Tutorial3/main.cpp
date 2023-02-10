/*
Previously: we set up OpenGL windowing and context library called GLFW
which initialize a graphics context for OpenGL

 ## USING MODERN OPENGL in C++

 Windows has graphics api called directX, OpenGL its not operating system related, its upto GPU manufacturers.
 Since we are on windows, we need to actually get all of the modern OpenGL functions, we need to get them from somewhere,
 OpenGL functions are implemented in you GPU drivers, so what we need to do, for any functionality newer than OpenGL 1.1,
 get into drivers and pull out the functions. Which means, get the function declerations and then link against functions.

 We need access to driver DLL files and just retrieve function pointers to the functions inside those libraries.

so for OpenGL if we want to do this manually, it wont be crssplatform, to access the drivers and pull out functions from that we need to use win32 api calls etc.
 loading library and loading function points all that, second problem we need to go thought all the opengl functions and implement it...

DOC: glew.sourceforce.net
We have simply library for this! : GLEW

all it does, it provides the OpenGL Api specification, kind of function declarations and symbol declarations, and contants and all that stuff
 for you in a header file and then the behind the scenes file (cpp) file the actual implementation of the library identifies what graphic drivers
 youre using, finds the appropriate DLL file and then loads all the function pointers.

 They dont implement the functions or anything they  just access functions that are already on you computer.



 DOC USAGE:
 You cant use OpenGL functions from glew, until you call glew.init
 You need to create a valid OpenGL rendering context before you call glewinit.


 in the lib folder if libname suffix with "s" letter thats the static library



 - ERROR HANDLING: UNRESOLVED external symbol -> means you have linking error. ORR like we havent use proper define symbol...

 for example: unresolved external symbol __imp__glewInit referenced function. when you go in the glewInit function in the glew.h file you will see
 you need GLEW_STATIC symbol. (because we are linking static library not dynamic library...)

To define symbol: go project properties, go C/C++ , go preprocessor and preprocessor definitions. write GLEW_STATIC;
be sure you are in the all configrutions in the properties window


 */