#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void init() {
    // Set the background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Enable point size setting
    glEnable(GL_PROGRAM_POINT_SIZE);
}

void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set point size
    glPointSize(10.0f);

    // Begin drawing points
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);     
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f, 0.0f);     
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.0f);    
    glEnd();

    // Swap buffers
    glfwSwapBuffers(glfwGetCurrentContext());
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << "ERROR" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Points", nullptr, nullptr);
    if (!window) {
        std::cerr << "ERROR" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "ERROR" << std::endl;
        return -1;
    }

    // Set up the OpenGL environment
    init();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here
        display();

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}