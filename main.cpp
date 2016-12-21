// main.cpp
#include "iostream"

#include "todos.h"

int main() {
  std::cout << "Hello, Welcome to my todos!!" << std::endl;

  Todos todos{};

  auto t1 = todos.add("Give a welcome");
  todos.add("Another todo");
  auto t2 = todos.add("Test another todo");

  todos.toggle(t1.id);
  todos.toggle(t2.id);

  todos.list();

  return 0;
}

