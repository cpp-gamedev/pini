#pragma once
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>


namespace pn::util {
// return vector of strings containing each line of the given file
std::vector<std::string> get_lines(std::filesystem::path const& filename);

// extract key-value pairs from given vector of strings and insert them in an
// unordered_map
std::unordered_map<std::string, std::string> insert_pairs(std::vector<std::string> const& file_lines);

std::string trim_whitespace(std::string const& str);

// data conversions:

double string_to_double(std::string const& str, double def = 0);

std::uint64_t string_to_uint64(std::string const& str, std::uint64_t def = 0);

std::int64_t string_to_int64(std::string const& str, std::uint64_t def = 0);

std::uint32_t string_to_uint32(std::string const& str, std::uint64_t def = 0);

std::int32_t string_to_int32(std::string const& str, std::uint64_t def = 0);

} // namespace pn::util
