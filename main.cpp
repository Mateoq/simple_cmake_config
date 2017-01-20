// main.cpp
#include "iostream"

#include <cstddef>
#include <array>
#include <memory>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "todos.h"

const int WIDTH = 690;
const int HEIGHT = 480;

int main() {
  std::cout << "Hello, Welcome to my todos!!" << std::endl;

  Todos todos{};

  auto t1 = todos.add("Give a welcome");
  todos.add("Another todo");
  auto t2 = todos.add("Test another todo");

  todos.toggle(t1.id);
  todos.toggle(t2.id);

  todos.list();

  // Make a window.
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit()) {
    std::cout << "Failed GLFW" << std::endl;
    return -1;
  }

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", nullptr, nullptr);
  if (!window) {
    std::cout << "Failed window" << std::endl;
    glfwTerminate();
    return -1;
  }

  /* Make the window context current */
  glfwMakeContextCurrent(window);

  /* Initialize OpenGL */
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed Glad" << std::endl;
    return -1;
  }

  // Define the viewport dimensions
  glViewport(0, 0, WIDTH, HEIGHT);

  /* Loop until the user closes the window */
  while(!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

