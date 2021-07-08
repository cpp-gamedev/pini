#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	std::string_view raw_input{"= 5\n#b=10\n c  = 23"};
	// std::filesystem::path filename{"/test/test.ini"};
	if (!pin.load_text(raw_input)) { return 1; }
	std::cout << pin.get_int32("a");
	std::cout << pin.get_int32("b");
	std::cout << pin.get_int32("c");
}
