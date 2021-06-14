#include "pini.hpp"
#include "util.hpp"
#include <vector>

namespace pn {

std::unordered_map<std::string, std::string> pn::reader::get_pairs() {
  return reader::key_value_pairs;
}
bool pn::reader::read_file(std::filesystem::path const &filename) {

  std::vector<std::string> file_lines = util::get_lines(filename);
  if (file_lines.empty()) {
    return false;
  }

  std::string key;
  std::string value;
  int delimeter_pos;

  for (auto str : file_lines) {
    delimeter_pos = str.find("=");
    if (delimeter_pos != std::string::npos) {
      key = str.substr(0, delimeter_pos);
      value = str.substr(delimeter_pos + 1);

      key_value_pairs.insert({key, value});
    }
  }
  return true;
}

} // namespace pn