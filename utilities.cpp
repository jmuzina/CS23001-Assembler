/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include "stack.hpp"
#include "utilities.hpp"
#include "../string/string.hpp"
#include <vector>

String infix_to_postfix(const String &str) {
	stack<String> expr;
	// Number of characters in the expression, not including the semicolon
	const int CAP = str.findch(0, ';') - 1;

	for (int i = 0; i < CAP; ++i) {
		String token, to_push;
		// Ignores parentheses and whitespace characters to construct each token
		while ((str[i] != ' ') && (str[i] != '\n') && (str[i] != '\r') && (str[i] != '\t') && (str[i] != '\0') &&
			(str[i] != ')') && (str[i] != '(') && (str[i] != '\0')) {
			token += str[i];
			++i;
		}
		// Add space between tokens
		if (token.capacity() >= 1)
			token += ' ';

		// Character that delimits a token - either a parenthesis or a whitespace character.
		const char DELIM = str[i];

		// Closing parentheses denote the end of a sub-expression.
		if (DELIM == ')') {
			// Pop the operands and operator off in infix order.
			String right = expr.pop();
			String oper = expr.pop();
			String left = expr.pop();
			// Re-order operands and operator in postfix order
			String postfix_concat = left + right + oper;
			to_push = postfix_concat;
		}
		// The sub-expression is not over yet; don't pop and re-order
		// Instead, set the token to be pushed onto the stack
		else
			to_push = token;

		// Push the token onto the stack if it's not a null string.
		if (to_push[0] != '\0') {
			expr.push(to_push);
		}
	}
	// Return the top of the stack without the space at the end
	return expr.top().substr(0, expr.top().capacity() - 3);
}

// Returns assembly operator
String get_operator(const String& s) {
	if (s == "+")
		return "AD";
	else if (s == "-")
		return "SB";
	else if (s == "*")
		return "MU";
	else if (s == "/")
		return "DV";
	else
		return "UNDEFINED";
}

// Returns whether a string is an operator
bool is_operator(const String s) {
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	else
		return false;
}

// Converts an expression to assembly instructions
String to_assembly(const String s, std::ofstream &out) {
	std::vector<String> tokens = s.split(' ');
	stack<String> expr;
	String lhs, rhs, op, token, result, tmp_string;
	const int SIZE = tokens.size();
	int temp_num = 1;
    
	out << "--------------------------\nExpression: " << s << "\nAssembly instructions: \n";
    
	for (int i = 0; i < SIZE; ++i) {
		String to_push;
		token = tokens[i];

		if (!is_operator(token))
			to_push = token;
		else { // Is an operator
			op = get_operator(token);
			rhs = expr.pop();
			lhs = expr.pop();
			tmp_string = result;
			to_push = evaluate(lhs, rhs, op, temp_num++, result, out);
			result = tmp_string + result;
		}
		expr.push(to_push);
	}
	return result;
}

//
String evaluate(const String lhs, const String rhs, const String op, int temp_num, String &result_assembler, std::ofstream &out) {
	String temp("TMP");

    // Append num to "TMP"
	while (temp_num > 0) {
		char c = (temp_num % 10) + '0'; // Take next place in temp_num, convert to char
		temp += c;
		temp_num /= 10;
	}

	String result("LD     " + lhs + '\n' + op + "     " + rhs + '\n' + "ST     " + temp + '\n');
	result_assembler = result; // Alters result in to_assembly
	out << result;

	return temp;
}
