#include <cstddef>
#include <cstdint>
#include <sstream>
#include <string_view>
#include <vector>
#include <pini/pini.hpp>
#include <pini/util.hpp>

namespace pn {
namespace {
pini::map_type read_file(std::filesystem::path const& filename) {
	std::vector<std::string> lines = util::get_lines(filename);
	return util::insert_pairs(lines);
}

pini::map_type read_text(std::string const& text) {
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

bool pini::load_text(std::string const& text) {
	key_value_pairs = read_text(text);
	return !key_value_pairs.empty();
}

double pini::get_double(std::string const& key, double def) const {
	auto it = key_value_pairs.find(key);
	if (it == key_value_pairs.end()) {
		if (pn::pini::on_msg) {
			std::stringstream str;
			str << "Key \"" << key << "\" not found.\n";
			(*pn::pini::on_msg)(str.str(), pn::pini::severity::warn);
		}
		return def;
	}
	return util::string_to_double(it->second);
}

std::uint64_t pini::get_uint64(std::string const& key, std::uint64_t def) const {
	if (auto it = key_value_pairs.find(key); it != key_value_pairs.end()) { return util::string_to_uint64(it->second); }
	if (pn::pini::on_msg) {
		std::stringstream str;
		str << "Key \"" << key << "\" not found.\n";
		(*pn::pini::on_msg)(str.str(), pn::pini::severity::warn);
	}
	return def;
}

std::int64_t pini::get_int64(std::string const& key, std::int64_t def) const {
	if (auto it = key_value_pairs.find(key); it != key_value_pairs.end()) { return util::string_to_int32(it->second); }
	if (pn::pini::on_msg) {
		std::stringstream str;
		str << "Key \"" << key << "\" not found.\n";
		(*pn::pini::on_msg)(str.str(), pn::pini::severity::warn);
	}
	return def;
}

std::uint32_t pini::get_uint32(std::string const& key, std::uint32_t def) const { return static_cast<std::uint32_t>(pini::get_uint64(key, def)); }

std::int32_t pini::get_int32(std::string const& key, std::uint32_t def) const { return static_cast<std::int32_t>(pini::get_int64(key, def)); }

std::string_view pini::get_string(std::string const& key) const {
	auto it = key_value_pairs.find(key);
	if (it == key_value_pairs.end()) {
		if (pn::pini::on_msg) {
			std::stringstream str;
			str << "Key \"" << key << "\" not found.\n";
			(*pn::pini::on_msg)(str.str(), pn::pini::severity::warn);
		}
		return {};
	}
	return it->second;
}

void pini::default_callback(std::string_view msg, severity level) {
	auto& out = level == severity::error ? std::cerr : std::cout;
	out << msg << '\n';
}

void pini::clear() { key_value_pairs.clear(); }
pini::const_iterator pini::erase(pini::const_iterator pos) { return key_value_pairs.erase(pos); }
pini::const_iterator pini::erase(pini::const_iterator first, pini::const_iterator last) { return key_value_pairs.erase(first, last); }
std::size_t pini::erase(std::string const& key) { return key_value_pairs.erase(key); }

} // namespace pn
