#pragma once

#include "util.hpp"
#include <filesystem>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace pn {
class reader {
  std::vector<std::string> file_lines;
  std::unordered_map<std::string, std::string> key_value_pairs;

public:
  std::unordered_map<std::string, std::string> get_pairs();
  // TODO remove excess whitespace from strings

  bool read_file(std::filesystem::path const &filename);

  // divide key-value pairs with `/`
  // NOTE Must pass string variable. String literal will cause an overload error
  bool read_file(std::string const &raw_string);
};
class pini {
  std::vector<std::string> file_lines;

public:
  int read_file(std::filesystem::path const &filename,
                std::vector<std::string> &file_lines);
};
} // namespace pn
