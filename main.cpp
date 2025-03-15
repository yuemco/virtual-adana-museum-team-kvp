// main.cpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback function to adjust the viewport when the window size changes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Process keyboard input
void processInput(GLFWwindow *window) {
    // Close window on pressing ESC
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    
    // Configure GLFW: OpenGL version 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Virtual Museum Assignment", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    // Set callback for window resize events
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLAD to load OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }
    
    // Set the viewport dimensions
    glViewport(0, 0, 800, 600);
    
    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Process input
        processInput(window);
        
        // Clear the screen with a dark gray background
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // TODO: Initialize and render your 3D scene here.
        //       - Load and compile your shaders.
        //       - Set up your 3D room and lighting.
        //       - Import and render the 3D models created in Blender.
        //       - Implement your mobile robot and robot arm logic.
        //       - Integrate UI elements for controlling the robot and lights.
        
        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Clean up and exit
    glfwTerminate();
    return 0;
}
