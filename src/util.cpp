#include "util.hpp"
#include <cassert>

namespace util {

std::vector<std::string> get_lines(std::filesystem::path const &filename) {
  std::vector<std::string> ret;
  std::string temp_line;
  if (auto file = std::ifstream(filename)) {
    while (std::getline(file, temp_line)) {
      ret.push_back(temp_line);
    }
  } else {
    std::cout << "File failed to open\n";
  }
  return ret;
}

std::unordered_map<std::string, std::string>
insert_pairs(std::vector<std::string> file_lines) {
  std::unordered_map<std::string, std::string> key_value_pairs;
  std::string key;
  std::string value;

  for (const auto &str : file_lines) {
    if (auto delimeter_pos = str.find('=');
        delimeter_pos != std::string::npos) {
      key = str.substr(0, delimeter_pos);
      value = str.substr(delimeter_pos + 1);

      key_value_pairs.insert({std::move(key), std::move(value)});
    }
  }
  return key_value_pairs;
}

} // namespace util