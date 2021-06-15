#include "pini.hpp"
#include "util.hpp"
#include <iostream>

int main() {
  pn::reader r;
  std::string raw_input = {"a=5/b = 10/ 123= abcd"};
  r.read_file(raw_input);
  std::unordered_map<std::string, std::string> key_value_pairs = r.get_pairs();
  for (const auto &pair : key_value_pairs) {
    std::cout << "key: " << pair.first << " value: " << pair.second << "\n";
  }
}