/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include <iostream>
#include "stack.hpp"
#include "../string/string.hpp"

int main() {
	{
		stack<int> actual;
		for (int i = 1; i <= 10; ++i)
			actual.push(i);
	
		stack<int> copy(actual);

		for (int i = 1; i <= 10; ++i)
			assert(copy.pop() == actual.pop());
	}
	{
		stack<char> actual;
		actual.push('a');
		actual.push('b');
		actual.push('c');
		actual.push('d');
		actual.push('e');
		actual.push('f');
		actual.push('g');

		stack<char> copy(actual);
		
		for (int i = 0; i < 7; ++i)
			assert(copy.pop() == actual.pop());
	}
	{
		stack<String> kenobi;
		kenobi.push("Mos ");
		kenobi.push("Eisley ");
		kenobi.push("spaceport ");
		kenobi.push("You ");
		kenobi.push("will ");
		kenobi.push("never ");
		kenobi.push("find ");
		kenobi.push("a ");
		kenobi.push("more ");
		kenobi.push("wretched ");
		kenobi.push("hive ");
		kenobi.push("of ");
		kenobi.push("scum ");
		kenobi.push("and ");
		kenobi.push("villainy");

		stack<String> copy(kenobi);
		assert(copy.pop() == "villainy");
		assert(copy.pop() == "and ");
		assert(copy.pop() == "scum ");
	}
	std::cout << "[UNIT TEST]: Stack copy constructor test ran successfully\n";
	return 0;
}
