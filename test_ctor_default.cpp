/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include "stack.hpp"
#include "../string/string.hpp"
#include <iostream>

int main() {
	{
		stack<int> test;
		assert(test.getTos() == 0);
		test.push(1);
		assert(test.getTos() != 0);
		assert(test.top() == 1);
	}
	{
		stack<String> test;
		assert(test.getTos() == 0);
		test.push("Hello world!");
		assert(test.getTos() != 0);
		assert(test.top() == "Hello world!");
	}
	{
		stack<char> test;
		assert(test.getTos() == 0);
		test.push('c');
		assert(test.getTos() != 0);
		assert(test.top() == 'c');
	}
	std::cout << "[UNIT TEST]: Stack default constructor test ran successfully.\n";
	return 0;
}
