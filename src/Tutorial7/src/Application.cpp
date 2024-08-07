#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

static unsigned int CompileShader(unsigned int type,const std::string& source){
    unsigned  int id = glCreateShader(type);
    const char* src = source.c_str(); //Giving pointer of first letter we can also say '&source[0]'
    //Make sure your src still alive cant be null.

    //Second Arg, How many source code are we specifying.
    //&src is double pointer, pointer address of pointer address it asks.
    //forth arg, if null string is assumed to be null terminated
    glShaderSource(id,1,&src, nullptr);
    glCompileShader(id);

    //TODO: error handling of shader code...
    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    //  unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    //Now we need to attach both of these shaders to our program.
    //This is like compiling c++ code. we got two different files and basicly we are linking them into one program.
    glAttachShader(program,vs);
    glAttachShader(program,fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(fs);
    glDeleteShader(vs);

    return program;
}

int main(void) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    //This is the line when we have OpenGL window context, you need to call glew init after that line
    glfwMakeContextCurrent(window);

    //Added line
    if (glewInit() != GLEW_OK) {
        std::cout << "ERROR GLEW NOT OK" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;


    // We can define vertex buffer, outside the while loop
    // Inside the while loop we can just say draw the data we define here. we can ofc change it every frame if we like.
    float positions[6] = {
            -0.5f, -0.5f,
            0.0f, 0.5f,
            0.5f, -0.5f
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer); //Generating buffer and giving us back its id.
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); //This size is in bytes...
    // gl_static means it will be modified once and used many times. (read the manual)

    glEnableVertexAttribArray(0);
    // first arg is index, which attribute index you are reffering to. which we used in the glEnableVertexAtribArray
    // second arg is the array couple size as count,
    // forth one, is normalized our float values already normalized. (For example color 0-255 need to be normalized)
    // fifth, stride. (in case we have something between our two float values. just jump lenght) since we use float in the array size  8*2 and last thing is offset if we have 3rd element in the array for another purpose
    // six, pointer to actual attribute. general offset. which bytes of begining in the data.
    //Each vertex type is a attribute, color is attrubute, normal is attribute...
    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float ) * 2 , 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        //second arg is basically offset, third arg number of indices to be renderered, (Vertexes in this case.)
        //What it will draw is, last currently binded buffer with glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}