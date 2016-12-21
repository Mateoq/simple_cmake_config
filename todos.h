#pragma once

#include <iostream>
#include <vector>
#include <string>

struct Todo {
  int id;
  std::string text;
  bool completed;
};

class Todos {
 public:
  Todos();

  Todo add(const std::string text);
  bool toggle(const int& id);

  void list();
 private:
  int m_Count;
  std::vector<Todo> m_Todos;
};

