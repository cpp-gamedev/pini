#include "util.hpp"

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

/* std::vector<std::string> separate_substrings(const std::string &str) {
  std::vector<std::string> ret;
  std::string word;
  std::stringstream s_stream(str);
  while (std::getline(s_stream, word, ' ')) {
    ret.push_back(word);
  }
  return ret;
} */

} // namespace util