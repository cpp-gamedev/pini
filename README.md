# PINI

Pini is a small C++ library for reading .pini files and storing them as key-value pairs.

## Pini syntax

A `.pini` file can contain key-value pairs of strings, as well as comments

```ini	
race = goblin
# these are the base stats that will change with levels
health = 90
attack = 20
defense = 40

```

## Usage

### Reading files

In order to parse `.pini` files, you first have to create a `pini` object:

```cpp
pn::pini pin
```

The `pini` object can then be initialized by either passing it a raw input string which follows the same standard `pini` syntax or passing it the path to a `.pini` file:

```cpp
pn::pini pin_file, pin_text;

std::filesystem::path filename{"path/to/text.pini"};
std::string_view raw_input{"race=goblin\nhealth=90"};

pin_file.load_file(filename);
pin_text.load_text(raw_input);
```

**Note about the input**:
All lines where the key is an empty string  and lines that start with `#` will be automatically ignored.
All excess whitespace will be automatically trimmed, unless the entire string is only whitespace, then noting will be changed.

` def =  90   `-> `def=90`

### Error handling

Errors and warnings are printed by default using:

```cpp
void pini::default_callback(std::string_view msg, severity level) {
	auto& out = level == severity::error ? std::cerr : std::cout;
	out << msg << '\n';
}
```

You can also use your own custom functions or turn it off:

```cpp
// for turning the warnigns off:
pin.on_msg = nullptr;

// for using your own custom functions

pin.on_msg = [](std::string_view msg, pn::pini::severity level) {
		auto& out = level == pn::pini::severity::error ? std::cerr : std::cout;
		out << "Custom: || " << msg << '\n';
	};

// or:
void custom_callback(std::string_view msg, severity level) {
	auto& out = level == severity::error ? std::cerr : std::cout;
	out <<"||" << msg << "||\n";
}
pin.on_msg = custom_callback;
```

### Getting values

All key-value pairs are stored inside an `std::unordered_map`, and can be retrieved using several different `get` functions: 

```cpp
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
```

Example: 

```cpp
double health = pin.get_double("health");
```

### Helper functions: 

`pini` also contains several helper functions that work like the ones for `std::unordered_map`:

- `is_empty()`
- `size()`
- `clear()`
- `erase()`
- `contains()`

