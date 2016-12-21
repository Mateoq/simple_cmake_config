#include "todos.h"

Todos::Todos() {
  this->m_Count = 0;
}

Todo Todos::add(const std::string text) {
  auto newTodo = Todo{this->m_Count++, text, false};
  this->m_Todos.push_back(newTodo);
  return newTodo;
}

bool Todos::toggle(const int& id) {
  return this->m_Todos[id].completed = !this->m_Todos[id].completed;
}

void Todos::list() {
  std::cout << "TODOS: " << std::endl;
  for(auto&& todo : this->m_Todos) {
    auto completed = (todo.completed) ? "true" : "false";
    std::cout <<
      "- Id: " << todo.id <<
      ", Text: " << todo.text <<
      ", Completed: " << completed << std::endl;
  }
}

