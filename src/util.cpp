#include <cassert>
#include <cctype>
#include <cstddef>
#include <pini/pini.hpp>
#include <pini/util.hpp>

namespace util {

std::vector<std::string> get_lines(std::filesystem::path const& filename) {
	std::vector<std::string> ret;
	std::string temp_line;
	if (auto file = std::ifstream(filename)) {
		while (std::getline(file, temp_line)) { ret.push_back(temp_line); }
	} else {
		if (pn::pini::on_msg_t) {
			std::stringstream str;
			str << "File \"" << filename << "\"failed to open \n";
			(*pn::pini::on_msg_t)(str.str(), pn::pini::severity::error);
		}
	}
	return ret;
}

std::unordered_map<std::string, std::string> insert_pairs(std::vector<std::string> file_lines) {
	std::unordered_map<std::string, std::string> key_value_pairs;
	std::size_t line_number = 0;
	for (const auto& str : file_lines) {
		++line_number;
		if (auto delimeter_pos = str.find('='); delimeter_pos != std::string::npos) {
			std::string const key = trim_whitespace(str.substr(0, delimeter_pos));
			if (key.empty() && pn::pini::on_msg_t) {
				std::stringstream str;
				str << "Line number " << line_number << " is not valid because the key is empty.\n";
				(*pn::pini::on_msg_t)(str.str(), pn::pini::severity::warn);
			} else {
				std::string const value = trim_whitespace(str.substr(delimeter_pos + 1));
				if (key[0] != '#') { key_value_pairs.insert({key, value}); }
			}
		}
	}
	return key_value_pairs;
}

std::string trim_whitespace(std::string const& str) {

	std::size_t start = 0;
	std::size_t end = str.size();
	while (std::isspace(str[start])) { ++start; }
	while (std::isspace(str[end - 1])) { --end; }
	if (end == start) { return str; }
	return str.substr(start, end - start);
}

} // namespace util
