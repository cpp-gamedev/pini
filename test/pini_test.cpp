#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	std::string_view raw_input{"a=5\nb=10\n23=c"};
	// std::filesystem::path filename{"/test/test.ini"};
	if (!pin.load_text(raw_input)) { return 1; }
	if (pin.get_int32("a") != 5) { return 1; }
}
