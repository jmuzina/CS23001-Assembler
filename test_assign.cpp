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
		stack<int> assignTo;
		for (int i = 1; i <= 10; ++i)
			assignTo.push(i);

		stack<int> lhs;
		assert(lhs.isEmpty());
		lhs = assignTo;
		assert(!(lhs.isEmpty()));
		assert(lhs.pop() == 10);
		assert(lhs.pop() == 9);
	}
	{
		stack<char> assignTo;
		assignTo.push('a');
		assignTo.push('b');
		assignTo.push('c');
		assignTo.push('d');
		assignTo.push('e');
		assignTo.push('f');

		stack<char> lhs;
		lhs = assignTo;
		
		for (int i = 0; i < 6; ++i)
			assert(lhs.pop() == assignTo.pop());
	}
	{
		stack<String> assignTo;
		assignTo.push("an");
		assignTo.push("eye");
		assignTo.push("for");
		assignTo.push("an");
		assignTo.push("eye");
		assignTo.push("makes");
		assignTo.push("the");
		assignTo.push("world");
		assignTo.push("go");
		assignTo.push("blind");

		stack<String> lhs;
		lhs = assignTo;
		
		for (int i = 0; i < 10; ++i)
			assert(lhs.pop() == assignTo.pop());
	}
	std::cout << "[UNIT TEST]: Stack assignment test ran successfully\n";
	return 0;
}
