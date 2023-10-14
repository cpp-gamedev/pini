#include <ios>
#include <iostream>
#include <pini/pini.hpp>

int main() {
	pn::pini pin;

	std::string raw_input{"health = 9\nattack = 4.5\nb=32\n#comment\ndef = -9.2314\nskill points = 8\n"};
	static int ret = 0;
	pn::pini::on_msg = [](std::string_view msg, pn::pini::severity level) {
		auto& out = level == pn::pini::severity::error ? std::cerr : std::cout;
		out << "Custom: || " << msg << '\n';
		if (level == pn::pini::severity::error) { ret = 1; }
	};
	if (!pin.load_text(raw_input)) { return 1; }
	if (pin.empty()) { return 1; }
	if (pin.contains({})) { return 1; }
	if (pin.contains("#comment")) { return 1; }
	if (pin.get_int32("health") != 9) { return 1; }

	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
	std::cout << pin.size() << " | " << pin.empty() << '\n';
	pin.erase("def");
	for (auto& pair : pin) { std::cout << pair.first << " " << pair.second << '\n'; }
	return ret;
}
