#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	// std::string_view raw_input{"a=5\nb=10\n23=c"};
	std::filesystem::path filename{"test/test.ini"};

	std::cout << std::boolalpha << pin.load_file(filename) << "\n";
	std::cout << "attack: " << pin.get_uint32("attack ") << "\n";
	std::cout << "def " << pin.get_uint64("def ") << "\n";
	std::cout << "health " << pin.get_int64("health ") << "\n";
	std::cout << "def " << pin.get_double("def ") << "\n";
	std::cout << "sp " << pin.get_int32("skill points ") << "\n";
}
