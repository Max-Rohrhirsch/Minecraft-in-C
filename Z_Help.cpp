// git pull https://github.com/Max-Rohrhirsch/Minecraft-in-C
// g++ main.cpp glad.c -ldl -lglfw && ./a.out

///////////////////////////////////////////////////////////////////////////
// IMPORTS
///////////////////////////////////////////////////////////////////////////

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;
void processInput(GLFWwindow *window);
void draw();
int shader();

///////////////////////////////////////////////////////////////////////////
// WINDOW
///////////////////////////////////////////////////////////////////////////

// SETTINGS
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;
const char* TITEL = "Minecraft";
const float bg_color[3] = {0.2f, 0.2f, 0.2f};

int createWindow() {
    glfwInit();

    //more Hints for Settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create Window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITEL, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    shader();
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(bg_color[0], bg_color[1], bg_color[2], 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


// createWindow();
///////////////////////////////////////////////////////////////////////////
// INPUT
///////////////////////////////////////////////////////////////////////////
/*
glfwSerKeyCallback(window, key_callback);  // bevore glViewport()
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS) // before glViewport
        activate_airship();
}
*/
///////////////////////////////////////////////////////////////////////////
// BUFFER
///////////////////////////////////////////////////////////////////////////
/*

glCreateBuffer(1, &myBufferId);
glBindBuffer(GL_ARRAY_BUFFER, myBufferId);
glBufferData(GL_ARRAY_BUFFER, sizeOfData, myData, usage);




*/
///////////////////////////////////////////////////////////////////////////
// SHADER
///////////////////////////////////////////////////////////////////////////

ind shader() {


    return 0;
}

///////////////////////////////////////////////////////////////////////////
// DRAW
///////////////////////////////////////////////////////////////////////////
void draw() {
    glClearColor(0.5f, 0.3f, 0.7f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = {
        -1.0f, -1.0f, 0.0f, // left
         0.5f, -0.5f, 0.0f, // right
         0.0f,  0.0f, -1.0f  // top
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // glDeleteVertexArrays(1, &VAO);
    // glDeleteBuffers(1, &VBO);
}

///////////////////////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////////////////////
int main() {
    createWindow();
    return 0;
}
