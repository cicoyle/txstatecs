/*****************************************************
Name: Cassandra Coyle
Date: 4/25/2017
Problem Number: 7
Hours spent solving the problem: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include <cstring>
#include "charStack.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//Function to check that the parenthese match in the equation
bool charStack::checkParenthesis(char var1, char var2) {
	bool result = false;
	
	if((var1 == ']' && var2 == '[') || (var1 == '}' && var2 == '{') || (var1 == ')' && var2 == '('))
		result = true;
	
	return result;
}

//Function to write to the output file
/*void charStack::validateFile(char arry[], int s, charStack st) {
	ofstream fout;
	fout.open("exp_output.dat", ios::app);
cout << "In write to file function." << endl;

	if(fout.fail())
	{
		cout << "Error: output file did not open." << endl;
		return;
	}	
cout << "Equation from write to file function: " << arry << endl;
	fout << arry;	
}
*/
//Function to check if the parentheses are balanced in the equation
bool charStack::checkSpecialCase(char arry[])
{
	ofstream fout;
	fout.open("exp_ouput.dat", ios::app);
	int fileLineSize = strlen(arry);
	bool result = true;
	charStack st(fileLineSize);
	int lB = 0;
	int lP = 0;
	int rB = 0;
	int rP = 0;
	int brack = 0;
	int para = 0;

	//Display the equation
	fout<< arry;

	//Go through each char in expression
	for(int i = 0; i < fileLineSize; i++) {	
		//If bracket or parenthese encountered
		if(arry[i] == '[' || arry[i] == '(') {
			st.push(arry[i]);
			
			if(arry[i] == '(')
				lP++;
			if(arry[i] == '[')
				lB++;  
		}

		if(arry[i] == ']' || arry[i] == ')') {
			if(arry[i] == ')')
				rP++;	
			if(arry[i] == ']')
				rB++;
		}
		if(checkParenthesis(arry[i], st.pop()) == false)
			result = false;
	}

	brack = lB - rB;
	para = lP - rP;	

	//If expression has an element missing, say it is missing something
	if(brack != 0 || para != 0)
		fout << " === missing ";

	//If expression has no elements missing, say it is valid
	else if(brack == 0 && para == 0)
		fout << " === valid expression";

	//Display what the expression is missing
	if(brack > 0)
		fout << abs(brack) << " ] ";
	if(brack < 0)
		fout << abs(brack) << " [ ";
	if(para > 0)
		fout << abs(para) << " ) ";
	if(para < 0)
		fout << abs(para) << " ( ";

cout << "RP " << rP << " LP " << lP << " RB " << rB << " LB " << lB <</*" RC " << rightCurly << " LC " << leftCurly << */endl;
	
	//Provide error message if more than 6 missing elements
	if((brack + para) > 6)
		fout << " Error: there are more than 6 elements missing from expression.";

	fout << endl;

	/*There exists a case where even after successful result from above statements
	still the possibility of imbalance exists; e.g., [{}()[()]  -->Missed one more 
	closing parenthesis. Check this case by checking stack space
	*/
	if(st.isEmpty() == false)
		result = false;

	return result;
}

//Constructor to initialize stack
charStack::charStack(int size)
{
	top = -1;
	stackSize = size;
	stackArray = new int(size);
}


//Destructor to get rid of the stack
charStack::~charStack() {delete [] stackArray;}

//Function to add to the stack
void charStack::push(int num)
{
	if(isFull())
		cout << "The stack is full. Nothing is added to the stack." << endl;

	else
	{
		top++;
		stackArray[top] = num;
	}
}

//Function to remove from the stack
char charStack::pop()
{
	if(top>=0)
        {
            	char ch = stackArray[top];
            	top--;
            	return ch;
        }
	return '\0';
}

//Check if the stack is full
bool charStack::isFull() const
{
	bool check;
	
	if(top == stackSize - 1)
		check = true;

	else
		check = false;

	return check;
}

//Check if the stack is empty
bool charStack::isEmpty() const
{
	bool check;

	if(top == -1)
		check = true;

	else
		check = false;

	return check;
}
