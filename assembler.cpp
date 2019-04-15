/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"
#include "utilities.hpp"

int main(int argc, char *argv[]) {
	if ((argc < 3) || (argc > 3)) {
		std::cout << "Usage: \n./assembler <input file path> <output file path>\n";
		exit(1);
	}

	std::ifstream in(argv[1]);
	if (in.fail()) {
		std::cerr << argv[1] << " failed to open or does not exist!\nExiting program.\n";
		exit(1);
	}

	std::ofstream out(argv[2]);
	if (out.fail()) {
		std::cout << argv[2] << " failed to write. Exiting program!\n";
		exit(1);
	}
	char c;
	in.get(c);
	out << argv[1] << " converted to assembly: \n";
	out << "-------------------------------------\n";
	while (!in.eof()) {
		while ((c != ';') && (!in.eof())) {
			String line(c);

			while ((c != ';') && (!in.eof())) {
				in.get(c);
				line += c;
			}

			if (line[0] != '\0')
				line += ";\n";
			if (!in.eof()) {
				String postfix(infix_to_postfix(line));
				String assembly(to_assembly(postfix, out));
			}
			if (!in.eof()) {
				in.get(c);
				while ((c == ';') && (!in.eof()))
					in.get(c);
			}
		}
	}
	out << "\n";
	out.close();
	std::cout << "Converted expressions have been written to " << argv[2] << "\n";

	in.close();

	return 0;
}
