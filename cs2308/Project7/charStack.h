/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 10
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef charStack_h
#define charStack_h
#include "charStack.h"

using namespace std;

class charStack {
	private:
		//array stack pointer
		int *stackArray;
		//size of stack
		int stackSize;
		//top of the stack
		int top;
	public:
		//constructor
		charStack(int size);
		
		//destructor
		~charStack();
		
		void push(int);
		char pop();
		bool isFull() const;
		bool isEmpty() const;
		bool checkParenthesis(char, char);
		bool checkSpecialCase(char []);

};

#endif




