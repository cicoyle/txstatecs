/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 21
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef thisStack_h
#define thisStack_h
#include "thisStack.h"

using namespace std;

//create stack class
class stack { 

	private:
		//dynamic array 
		char *arry;

		//array size
		int stackSize;

		//variable for top of stack
		int top;
	public:
		//constructor
		stack(int size);

		//destructor
		~stack();

		bool push(char);
		char pop();
		bool isFull();
		bool isEmpty();
		bool checkMatch(char, char);
		bool checkElementsBalanced(char []);		
};

#endif
