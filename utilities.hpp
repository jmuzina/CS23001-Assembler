/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include "stack.hpp"
#include "../string/string.hpp"
#include <fstream>

String infix_to_postfix(const String&);
String infix_to_prefix(const String&);
String get_operator(const String&);
bool is_operator(const String);
String to_assembly(const String, std::ofstream&);
String evaluate(const String, const String, const String, int, String&, std::ofstream&);

#endif
