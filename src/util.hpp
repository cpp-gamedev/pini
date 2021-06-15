#pragma once
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace util {
// return vector of strings containing each line of the given file
std::vector<std::string> get_lines(std::filesystem::path const &filename);

// extract key-value pairs from given vector of strings and insert them in an
// unordered_map
std::unordered_map<std::string, std::string>
insert_pairs(std::vector<std::string> file_lines);
} // namespace util