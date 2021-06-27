#include "pini.hpp"
#include <cstddef>
#include <cstdint>
#include <sstream>
#include <string_view>
#include <vector>
#include "util.hpp"

namespace pn {
namespace {
pini::map_type read_file(std::filesystem::path const& filename) {
	std::vector<std::string> lines = util::get_lines(filename);
	return util::insert_pairs(lines);
}

pini::map_type read_text(std::string_view text) {
	std::string str;
	std::stringstream str_stream;
	str_stream << text;
	std::vector<std::string> lines;
	while (getline(str_stream, str, '\n')) { lines.push_back(str); }
	return util::insert_pairs(lines);
}

} // namespace

bool pini::load_file(std::filesystem::path const& filename) {
	key_value_pairs = read_file(filename);
	return !key_value_pairs.empty();
}

bool pini::load_text(std::string_view text) {
	key_value_pairs = read_text(text);
	return !key_value_pairs.empty();
}

double pini::get_double(std::string const& key, double def) const {
	auto it = key_value_pairs.find(key);
	if (it == key_value_pairs.end()) { return def; }
	return std::atof(it->second.c_str());
}

std::uint64_t pini::get_uint64(std::string const& key, std::uint64_t def) const {
	if (auto it = key_value_pairs.find(key); it != key_value_pairs.end()) {
		try {
			return stoull(it->second);
		} catch (std::exception const& e) { std::cerr << e.what() << '\n'; }
	}
	return def;
}

std::int64_t pini::get_int64(std::string const& key, std::int64_t def) const {
	if (auto it = key_value_pairs.find(key); it != key_value_pairs.end()) {
		try {
			return stoll(it->second);
		} catch (std::exception const& e) { std::cerr << e.what() << '\n'; }
	}
	return def;
}

std::uint32_t pini::get_uint32(std::string const& key, std::uint32_t def) const { return static_cast<std::uint32_t>(pini::get_uint64(key, def)); }

std::int32_t pini::get_int32(std::string const& key, std::uint32_t def) const { return static_cast<std::int32_t>(pini::get_int64(key, def)); }

std::string_view pini::get_string(std::string const& key) const {
	auto it = key_value_pairs.find(key);
	if (it == key_value_pairs.end()) { return {}; }
	return it->second;
}
} // namespace pn
