/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 10
Instructor: Komogortsev, TSU
*****************************************************/

#include "charStack.h"
#include <iostream>
#include<string.h>

using namespace std;

//constructor 
charStack::charStack(int size) {
	top = -1;
	stackSize = size;
	stackArray = new int[size];
}

//destructor
charStack::~charStack() { delete [] stackArray;}

//push to stack
void charStack::push(int value) {
	if(isFull())
		cout << "Stack is full. " << endl;
	else {
		top++;
		stackArray[top] = value;
	}
}

//pop from stack
char charStack::pop() {
/*	if(isEmpty())
		cout << "Stack is empty. " << endl;
	else {
		value = stackArray[top];
		top--;
	}
*/
	if(top >= 0) {
		char ch = stackArray[top];
		top--;
		return ch;
	}
	return '\0';
}

//check if stack is full
bool charStack::isFull() const {
	bool status;
	
	if(top == stackSize - 1)
		status = true;
	else
		status = false;
return status;
}

//check if stack is empty
bool charStack::isEmpty() const {
	bool status;
	
	if(top == -1)
		status = true;
	else
		status = false;
return status;
}

//check that parenthesis are correct function
bool charStack::checkParenthesis(char ch1, char ch2) {
    	bool result = false;
    	if((ch1 == ']' && ch2 == '[') || (ch1 == '}' && ch2 == '{') ||
          (ch1 == ')' && ch2 == '(') )
        
	result = true;
	return result;
}

//check the special case function
bool charStack::checkSpecialCase(char arry[]) {
    	int arrySize = strlen(arry);
	bool result = true;
	charStack pancakeStack(arrySize);

    	for(int i = 0; i < arrySize; i++) {
        	if((arry[i] == '[') || (arry[i] == '{') || (arry[i] == '('))
        	    pancakeStack.push(arry[i]);
        	
		else if((arry[i] == ']') || (arry[i] == '}') || (arry[i] == ')')) {
       		 	if(checkParenthesis(arry[i], pancakeStack.pop()) == false) {
                		result = false;
                		break;
            		}
		}
    	}
  if(pancakeStack.isEmpty() == false)
        result = false;

    return result;
}


