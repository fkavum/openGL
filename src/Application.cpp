#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

static unsigned int CompileShader(unsigned  int type,const std::string& source){
    unsigned  int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id,1,&src, nullptr);
    glCompileShader(id);

    //TODO: error handling...

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    //  unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

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

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //Added line
    if (glewInit() != GLEW_OK) {
        std::cout << "ERROR GLEW NOT OK" << std::endl;
    }

    float positions[6] = {
            -0.5f, -0.5f,
            0.0f, 0.5f,
            0.5f, -0.5f
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    //the array couple size, since we use float in the array size siz 8*2 and last thing is offset if we have 3rd element in the array for another purpose
    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float ) * 2 , 0);

    //Added line end

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glDrawArrays(GL_TRIANGLES,0,3);
        /*glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
*/



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}