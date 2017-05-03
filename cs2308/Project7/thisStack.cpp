/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 21
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
        arry = new char(size);                                                         
}                                                                                            
                                                                                             
//destructor to delete array                                                                 
stack::~stack() { delete [] arry;}                                                     
                                                                                             
//function to push (add) to stack                                                            
bool stack::push(char value) {                                                                   
        //if top is smaller than size-1                                                      
        if (top < SIZE-1) {                                                                  
                //increment the top                                                          
                top++;                                                                       
                                                                                             
                //assign value in array                                                      
                arry[top] = value;                                                         
                                                                                             
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
                char value = arry[top];                                                    
                                                                                             
                //decrement the top                                                          
                top--;                                                                       
                                                                                             
                return value;                                                                    
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
bool stack::checkMatch(char var1, char var2) {                                                 
        //if all of the parenthesis and brackets match                                       
        if((var1 == ']' && var2 == '[') || (var1 == ')' && var2 == '(') )                        
                return true;                                                                 
        else                                                                                 
                return false;                                                                
}                                                                                            
                                                                                             
//function to check the parenthesis/brackets are balanced                                    
bool stack::checkElementsBalanced(char fileLineArray[]) {                                                      
        //variable to the length of the array                                                
        int arryLength;
	
	//assign array length
	arryLength = strlen(fileLineArray);                                                              
                                                                                             
        //stack object                                                                       
        stack panStack(SIZE);                                                                
                                                                                             
        //for loop to run through the length of the array                                    
        for(int i = 0; i < arryLength; i++) {                                                       
                if((fileLineArray[i] == '[') || (fileLineArray[i] == '('))                                     
                    panStack.push(fileLineArray[i]);                                                  
                                                                                             
                else if((fileLineArray[i] == ']') || (fileLineArray[i] == ')'))                                
                        if(panStack.checkMatch(fileLineArray[i],panStack.pop()) == false)             
                                return false;                                                
        }                                                                                    
                                                                                             
        if(panStack.isEmpty() == false)                                                      
                return false;                                                                
                                                                                             
    return true;                                                                             
}                                                                                            
