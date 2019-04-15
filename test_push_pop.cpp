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
		stack<int> integers;
		integers.push(1);
		
		assert(integers.top() == 1);
		
		integers.push(2);
		assert(integers.top() == 2);

		assert(integers.pop() == 2);
		assert(integers.pop() == 1);
		assert(integers.getTos() == 0);
	}
	{
		stack<char> helloWorld;
		String str("Hello world!");

		for (int i = str.capacity(); i != -1; --i)
			helloWorld.push(str[i]);
		
		for (int i = 0; i < str.capacity(); ++i)
			assert(helloWorld.pop() == str[i]);
	}
	{
		stack<String> sentence;
		sentence.push("methods!");
		sentence.push("pop ");
		sentence.push("and ");
		sentence.push("push ");
		sentence.push("the ");
		sentence.push("test ");
		sentence.push("to ");
		sentence.push("designed ");
		sentence.push("sentence ");
		sentence.push("a ");
		sentence.push("is ");
		sentence.push("This ");

		assert(sentence.pop() == "This ");
		assert(sentence.pop() == "is ");
		assert(sentence.pop() == "a ");
		assert(sentence.pop() == "sentence ");
		assert(sentence.pop() == "designed ");
		assert(sentence.pop() == "to ");
		assert(sentence.pop() == "test ");
		assert(sentence.pop() == "the ");
		assert(sentence.pop() == "push ");
		assert(sentence.pop() == "and ");
		assert(sentence.pop() == "pop ");
		assert(sentence.pop() == "methods!");
		assert(sentence.getTos() == 0);
	}
	std::cout << "[UNIT TEST]: Stack push/pop test ran successfully\n";
	return 0;
}
