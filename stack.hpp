/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <new>
#include <cassert>
#include "../string/string.hpp"

template<typename T>
class node {
public:
	node() : next(0) {};
	node(const T& item) : data(item), next(0) {};
	T 		    getData() const { return data; };
	node<T>* 	getNext() const { return next; };
	void 		setNext(const node<T>* newNext) { next = newNext; };
	void 		setNext(node<T>* newNext) { next = newNext; };
private:
	T 		data;
	node<T> *next;
};

template <typename T>
class stack {
public:
	stack() { tos = 0; };
	stack(const stack<T>&);
	~stack();
	void		swap(stack<T>&);
	stack<T>& 	operator=	(stack<T> rhs) { swap(rhs); return *this; };
	bool      	isEmpty() const { return tos == 0; };
	bool     	isFull() const;
	T		    top() const { return tos->getData(); };
	T         	pop();
	void      	push(const T&);
	node<T>*	getTos() const { return tos; };

private:
	node<T>   	*tos;
};

// Destructor
template <typename T>
stack<T>::~stack() {
	node<T> *temp = 0;
	while (tos != 0) {
		temp = tos;
		tos = tos->getNext();
		delete temp;

	}
}

// Copy constructor
template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {
	node<T> *temp = actual.tos, *bottom;
	while (temp != 0) {
		if (tos == 0) {
			tos = new node<T>(temp->getData());
			bottom = tos;
		}
		else {
			node<T>* newNode = new node<T>(temp->getData());
			bottom->setNext(newNode);
			bottom = bottom->getNext();
		}
		temp = temp->getNext();
	}
}

template <typename T>
void stack<T>::push(const T& item) {
	assert(!isFull());
	node<T> *temp = new node<T>(item);
	temp->setNext(tos);
	tos = temp;
}

template <typename T>
T stack<T>::pop() {
	assert(!isEmpty());
	T result = tos->getData();
	node<T> *temp = tos;
	tos = tos->getNext();
	delete temp;
	return result;
}

// Constant time swap
template<typename T>
void stack<T>::swap(stack<T>& rhs) {
	node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

template<typename T>
bool stack<T>::isFull() const {
	node<T> *temp = new(std::nothrow) node<T>(); // If this fails, we're out of memory
	if (temp == 0)
		return true;
	delete temp;
	return false;
}

#endif
