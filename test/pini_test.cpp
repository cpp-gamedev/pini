#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	// std::string_view raw_input{"= 5\n#b=10\n c  = 23"};
	std::filesystem::path filename{"test/test.pini"};
	if (!pin.load_file(filename)) { return 1; }
	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
	std::cout << pin.size() << " | " << pin.is_empty();
	pin.erase("def");
	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
}
