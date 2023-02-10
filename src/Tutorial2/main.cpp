/* THERE IS HOW TO ADD LIB. DOC what is static/dynamic linking etc...

 ## Setting up OpenGL and Creating a Window in C++

Our goal creating window:
- Windowing actually depends on operating system spesific, for example if we want win32 api
- we will windowing creating code, glfw (create opengl context and windowing) not drawing triangle or smt like that.
- if we want to do that by our self, we need to code 3 times...



DOC: @see www.glfw.org/documentation.html

- if this was a serious application, we would probably download the source code, build it to ourselfs and
 we would add it as seperate project and compile it to the static library and then link it with my main app.

- but we will: Get prebuild library and build with that

- For windows: what metters of not the operating system architeture you application architecture in order to pick x64 or x32 prebuilds
    There will be include and lib files in the prebuild library...

- To add prebuild lib... ->
    - right click solution and go properties
    - Make sure you are in allConfigurations
    - To Include dir -> go c++ say $(SolutionDir)/Dependencies/../include
    - To inlude lib folder -> go : Linker->General-> AdditionalLibraryDirectories -> $(SolutionDir)/Dependencies/../lib
    - To include lib -> go: Linker -> Input -> glfw3.lib | also link opengl32.lib,User32.lib,Gdi32.lib, Shell32.lib


if we dont link all the external libs like opengl32/User32 etc it will compile succesfull but not linked succesfully we cant have build!

 -    Where to find which library to add -> you can read the OUTPUT it will say something like:

    unresolved external symbol _imp_XXXXX reference in function .... You can just search this in google to find lib name

/*
in the lib folder if libname suffix with "s" letter thats the static library

A static library(.a) is a library that can be linked directly into the final executable produced by the linker,it is contained in it and there is no need to have the library into the system where the executable will be deployed.

A shared library(.so) is a library that is linked but not embedded in the final executable, so will be loaded when the executable is launched and need to be present in the system where the executable is deployed.

A dynamic link library on windows(.dll) is like a shared library(.so) on linux but there are some differences between the two implementations that are related to the OS (Windows vs Linux) :

A DLL can define two kinds of functions: exported and internal. The exported functions are intended to be called by other modules, as well as from within the DLL where they are defined. Internal functions are typically intended to be called only from within the DLL where they are defined.

An SO library on Linux doesn't need special export statement to indicate exportable symbols, since all symbols are available to an interrogating process.


 What heard


 Static libraries (.a files): At link time, a copy of the entire library is put into the final application so that the functions within the library are always available to the calling application
 Shared objects (.so files): At link time, the object is just verified against its API via the corresponding header (.h) file. The library isn't actually used until runtime, where it is needed.

 ToSum up:


- Shared Object: A library that is automatically linked into a program when the program starts, and exists as a standalone file.
 The library is included in the linking list at compile time (ie: LDOPTS+=-lmylib for a library file named mylib.so). T
 he library must be present at compile time, and when the application starts.
- Static Library: A library that is merged into the actual program itself at build time for a single (larger) application containing the application code and the library code
 that is automatically linked into a program when the program is built, and the final binary containing both the main program and the library itself exists
 as a single standalone binary file. The library is included in the linking list at compile time (ie: LDOPTS+=-lmylib for a library file named mylib.a).
 The library must be present at compile time.
- DLL: Essentially the same as a shared object, but rather than being included in the linking list at compile time, the library is loaded via dlopen()/dlsym()
 commands so that the library does not need to be present at build time for the program to compile. Also, the library does not need to be present (necessarily)
 at application startup or compile time, as it is only needed at the moment the dlopen/dlsym calls are made.
- Shared Archive: Essentially the same as a static library, but is compiled with the "export-shared" and "-fPIC" flags. The library is included in the
 linking list at compile time (ie: LDOPTS+=-lmylibS for a library file named mylibS.a). The distinction between the two is that this additional flag is required
 if a shared object or DLL wants to statically link the shared archive into its own code AND be able to make the functions in the shared object available to other
 programs, rather than just using them internal to the DLL. This is useful in the case when someone provides you with a static library, and you wish to repackage
 it as an SO. The library must be present at compile time.

 */