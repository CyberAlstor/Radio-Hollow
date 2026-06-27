#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWmonitor* mon = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(mon);

  GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Radio Hollow", mon, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window/n";
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD/n";
    return -1;
  }

  glViewport(0, 0, mode->width, mode->height);

  while(!glfwWindowShouldClose(window)) {
    // render code
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
    glfwPollEvents();    
  }
  
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 
