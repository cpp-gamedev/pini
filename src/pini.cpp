#include "pini.hpp"
#include "util.hpp"
#include <cstddef>
#include <sstream>
#include <vector>

namespace pn {

std::unordered_map<std::string, std::string> pn::reader::get_pairs() {
  return reader::key_value_pairs;
}
bool pn::reader::read_file(std::filesystem::path const &filename) {

  file_lines = util::get_lines(filename);
  if (file_lines.empty()) {
    return false;
  }
  key_value_pairs = util::insert_pairs(file_lines);

  return true;
}
bool pn::reader::read_file(std::string const &raw_string) {
  std::string str;
  std::istringstream str_stream(raw_string);
  while (getline(str_stream, str, '/')) {
    file_lines.push_back(str);
  }
  key_value_pairs = util::insert_pairs(file_lines);

  return true;
}
} // namespace pn