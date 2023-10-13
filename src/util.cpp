#include <cctype>

#include <pini/pini.hpp>
#include <pini/util.hpp>
namespace pn {
std::vector<std::string> util::get_lines(std::filesystem::path const& filename) {
	std::vector<std::string> ret;
	std::string temp_line;
	if (auto file = std::ifstream(filename)) {
		while (std::getline(file, temp_line)) { ret.push_back(temp_line); }
	} else {
		if (pn::pini::on_msg) {
			std::stringstream str;
			str << "File \"" << filename << "\"failed to open \n";
			(*pn::pini::on_msg)(str.str(), pn::pini::severity::error);
		}
	}
	return ret;
}

std::unordered_map<std::string, std::string> util::insert_pairs(std::vector<std::string> const& file_lines) {
	std::unordered_map<std::string, std::string> key_value_pairs;
	std::size_t line_number = 0;
	for (const auto& str : file_lines) {
		++line_number;
		if (auto delimeter_pos = str.find('='); delimeter_pos != std::string::npos) {
			std::string const key = trim_whitespace(str.substr(0, delimeter_pos));
			if (key.empty()) {
				if (pn::pini::on_msg) {
					std::stringstream str;
					str << "Line number " << line_number << " is not valid because the key is empty.\n";
					(*pn::pini::on_msg)(str.str(), pn::pini::severity::warn);
				}
			} else {
				std::string const value = trim_whitespace(str.substr(delimeter_pos + 1));
				if (key[0] != '#') { key_value_pairs.insert({std::string(key), std::string(value)}); }
			}
		}
	}
	return key_value_pairs;
}

std::string util::trim_whitespace(std::string const& str) {
	if (str.empty()) { return {}; }
	std::size_t start = 0;
	std::size_t finish = str.size();
	while (std::isspace(str[start])) { ++start; }
	while (std::isspace(str[finish - 1])) { --finish; }
	if (finish == start) { return str; }
	return str.substr(start, finish - start);
}

double util::string_to_double(std::string const& str, double def) {
	try {
		return stod(str);
	} catch (std::exception const& e) {
		if (pini::on_msg) { (*pini::on_msg)(e.what(), pini::severity::warn); }
	}
	return def;
}

std::uint64_t util::string_to_uint64(std::string const& str, std::uint64_t def) {
	try {
		return stoull(str);
	} catch (std::exception const& e) {
		if (pini::on_msg) { (*pini::on_msg)(e.what(), pini::severity::warn); }
	}
	return def;
}

std::int64_t util::string_to_int64(std::string const& str, std::uint64_t def) {
	try {
		return stoll(str);
	} catch (std::exception const& e) {
		if (pini::on_msg) { (*pini::on_msg)(e.what(), pini::severity::warn); }
	}
	return def;
}

std::uint32_t util::string_to_uint32(std::string const& str, std::uint64_t def) { return static_cast<std::uint32_t>(string_to_uint64(str, def)); }

std::int32_t util::string_to_int32(std::string const& str, std::uint64_t def) { return static_cast<std::int32_t>(string_to_int64(str, def)); }
} // namespace pn
