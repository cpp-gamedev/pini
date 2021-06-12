#pragma once

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace util {
// return vector of strings containing each line of the given file
std::vector<std::string> get_lines(std::filesystem::path const &filename);

// returns a vector of words contained in a string
// std::vector<std::string> separate_substrings(const std::string &str);
} // namespace util