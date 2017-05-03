/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include <fstream>
#include <cmath>
#include <iostream>
#include <string.h>
#include "thisStack.h"
#define SIZE 300
//constructor to initialize stack
stack::stack(int size) {
	//assign top to -1
	top = -1;
	
	//assign size
	stackSize = size;

	//allocate memory
	stackArray = new char(size);
}

//destructor to delete array
stack::~stack() { delete [] stackArray;}
                            
//function to push (add) to stack      
bool stack::push(char c) { 
	//if top is smaller than size-1                                 
	if (top < SIZE-1) {            
		//increment the top                  
		top++;             

		//assign value in array        
		stackArray[top] = c;       

		return true;               
	}                    

	//check if the stack is full
	if(isFull())
		return false;          
	
	return false;                  
}

//function to pop (remove) from stack                                  
char stack::pop() {                  
	//if top is bigger than or equal to 0                
	if(top >= 0){
	 	//assign array top to value                             
	        char c = stackArray[top];  
		
		//decrement the top
	        top--;             
        
	        return c;                  	
	}                              

	return '\0';                   
}

//function to see if the stack is full                                  
bool stack::isFull() {                
	bool returnType = false;

	//if the top is bigger than the size-1                  
	if(top >= SIZE-1)
		returnType = true;                   
	
	return returnType;                  
}                                  

//function to see if the stack is empty
bool stack::isEmpty() {
	bool returnType = false;
   
	//if the top is smaller than 0                  
	if(top < 0)        
		returnType = true;                           
	
	return returnType;                  
}           

//function to check that all of the parenthesis/brackets match
bool stack::checkMatch(char ch1, char ch2) {
	//if all of the parenthesis and brackets match
	if((ch1 == ']' && ch2 == '[') || (ch1 == ')' && ch2 == '(') )
        	return true;
	else
		return false;
}

//function to check the parenthesis/brackets are balanced
bool stack::checkBalance(char equa[]) {
	//variable to the length of the array
	int len = strlen(equa);

	//stack object
	stack panStack(SIZE);

	//for loop to run through the length of the array
	for(int i = 0; i < len; i++) {
        	if((equa[i] == '[') || (equa[i] == '('))
                    panStack.push(equa[i]);
        
        	else if((equa[i] == ']') || (equa[i] == ')'))
            		if(panStack.checkMatch(equa[i],panStack.pop()) == false)
                		return false;
    	}

    	if(panStack.isEmpty() == false)
        	return false;

    return true;
}  
