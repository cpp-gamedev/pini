#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	// std::string_view raw_input{"= 5\n#b=10\n c  = 23"};
	std::filesystem::path filename{"/home/nikolaj/projects/cpp/pini/test/test.pini"};
	static int ret = 0;
	pin.on_msg = [](std::string_view msg, pn::pini::severity level) {
		auto& out = level == pn::pini::severity::error ? std::cerr : std::cout;
		out << "Custom: || " << msg << '\n';
		if (level == pn::pini::severity::error) { ret = 1; }
	};
	if (!pin.load_file(filename)) { return 1; }
	if (pin.is_empty()) { return 1; }
	if (pin.contains({})) { return 1; }
	if (pin.contains("#comment")) { return 1; }
	if (pin.get_int32("health") != 9) { return 1; }

	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
	std::cout << pin.size() << " | " << pin.is_empty();
	pin.erase("def");
	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
	return ret;
}
