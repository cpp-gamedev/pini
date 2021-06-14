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
  bool read_file(std::filesystem::path const &filename);
};
class pini {
  std::vector<std::string> file_lines;

public:
  int read_file(std::filesystem::path const &filename,
                std::vector<std::string> &file_lines);
};
} // namespace pn
