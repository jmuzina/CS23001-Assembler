/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include "utilities.hpp"
#include "../string/string.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if ((argc < 2) || (argc > 3)){
        std::cout << "Usage: \n./postfix <input file path> <output file path>\n";
        std::cout << "If no output file path is specified, postfix output will display ";
        std::cout << "in the console.\n";
        exit(1);
    }
        
    std::ifstream in(argv[1]);
    if (in.fail()) {
        std::cerr << argv[1] << " failed to open or does not exist!\nExiting program.\n";
        exit(1);
    }
    
    // Printing postfix expressions to console
    if (argc == 2) {
        char c;
        in.get(c);
        std::cout << "\n" << argv[1] << " converted to postfix: \n";
        std::cout << "-------------------------------------\n";
        while (!in.eof()) {
            String line(c);
            if (!in.eof())
                in.get(c);
            else
                exit(1);
            while ((c != ';') && (!in.eof())) {
                line += c;
                in.get(c);
            }
            if (line[0] != '\0')
                line += ";\n";
            if ((argc == 2) && (!in.eof())) {
                std::cout << infix_to_postfix(line) << "\n";
            }
            if (!in.eof()) {
                in.get(c);
                while ((c == ';') && (!in.eof()))
                    in.get(c);
            }
        }
        std::cout << "\n";
    }
    // Writing postfix expressions to file
    else if (argc == 3) {
        std::ofstream out(argv[2]);
        if (out.fail()) {
            std::cout << argv[2] << " failed to write. Exiting program!\n";
            exit(1);
        }
        char c;
        in.get(c);
        out << argv[1] << " converted to postfix: \n";
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
                    out << infix_to_postfix(line) << "\n";
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
        std::cout << "Converted postfix expressions have been written to " << argv[2] << "\n";
    }
    in.close();
    return 0;
}
