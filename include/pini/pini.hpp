#pragma once

#include <cstdint>
#include <filesystem>
#include <sstream>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace pn {
class pini {
  public:
	using map_type = std::unordered_map<std::string, std::string>;

	map_type const& get_pairs() const { return key_value_pairs; }
	bool load_file(std::filesystem::path const& filename);
	bool load_text(std::string_view text);

	// return double
	double get_double(std::string const& key, double def = 0) const;
	// return unsigned 64 bit integer - <unsigned long long>
	std::uint64_t get_uint64(std::string const& key, std::uint64_t def = 0) const;
	// return signed 64 bit integer  - <long long>
	std::int64_t get_int64(std::string const& key, std::int64_t def = 0) const;

	// return unsigned 32 bit integer
	std::uint32_t get_uint32(std::string const& key, std::uint32_t def = 0) const;
	// return signed 32 bit integer
	std::int32_t get_int32(std::string const& key, std::uint32_t def = 0) const;
	// return string value
	std::string_view get_string(std::string const& key) const;

  private:
	map_type key_value_pairs;
};
} // namespace pn
