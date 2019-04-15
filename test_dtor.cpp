/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"

int main() {
	{
		stack<int> test;
		for (int i = 1; i <= 10; ++i)
			test.push(i);

		assert(!(test.isEmpty()));
		assert(test.pop() == 10);

		test.~stack();
		assert(test.getTos() == 0);
		assert(test.isEmpty());
	}
	{
		stack<char> test;
		test.push('a');
		test.push('b');
		test.push('c');
		test.push('d');

		assert(!(test.isEmpty()));
		assert(test.pop() == 'd');
		
		test.~stack();

		assert(test.getTos() == 0);
		assert(test.isEmpty());
	}
	{
		stack<String> test;
		test.push("We're ");
		test.push("gonna ");
		test.push("need ");
		test.push("a ");
		test.push("bigger ");
		test.push("boat!");

		assert(!(test.isEmpty()));
		assert(test.pop() == "boat!");

		test.~stack();

		assert(test.getTos() == 0);
		assert(test.isEmpty());
	}
	std::cout << "[UNIT TEST]: Stack destructor test ran successfully\n";
	return 0;
}
