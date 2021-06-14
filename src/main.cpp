#include "pini.hpp"
#include "util.hpp"
#include <iostream>

int main() {
  pn::reader r;
  r.read_file("test.ini");
  std::unordered_map<std::string, std::string> key_value_pairs = r.get_pairs();
  for (const auto &pair : key_value_pairs) {
    std::cout << "key: " << pair.first << " value: " << pair.second << "\n";
  }
}