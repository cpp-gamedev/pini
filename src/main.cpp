#include "util.hpp"
#include <iostream>

int main() {
  std::vector<std::string> lines = util::get_lines("src/main.cpp");
  for (auto str : lines) {
    std::cout << str << std::endl;
  }
  std::cout << "\n";
}