#pragma once

#include <cstddef>
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

	// iteration

	using const_iterator = map_type::const_iterator;

	const_iterator begin() const { return key_value_pairs.begin(); }
	const_iterator end() const { return key_value_pairs.end(); }

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

	enum class severity { error, warn, info };
	using on_msg_t = void (*)(std::string_view, severity);
	static void default_callback(std::string_view msg, severity level);
	inline static on_msg_t on_msg = &default_callback;

	bool is_empty() const { return key_value_pairs.empty(); }
	std::size_t size() const { return key_value_pairs.size(); }
	void clear();
	const_iterator erase(const_iterator pos);
	const_iterator erase(const_iterator first, const_iterator last);
	std::size_t erase(std::string const& key);
	bool contains(std::string const& key) const;

  private:
	map_type key_value_pairs;
};
// implementation starts here
inline bool pini::contains(std::string const& key) const { return key_value_pairs.find(key) != key_value_pairs.end(); }
} // namespace pn
