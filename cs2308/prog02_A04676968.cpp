/**********************************
Name: Cassandra Coyle
Date: 2/14/17
Problem Number: 02
Hours spent solving the problem:
Instructor: Komogortsev, TSU
***********************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;

//prototypes
int validatefiles();
void getToken(char * studentinfo, int position);

ifstream fin;
ofstream fout;

int main()
{
	fin.open("student_input.dat");
	fout.open("student_results.dat");
	validatefiles();
	//variables 
	char studentinfo[256];
	int position = 0;	
		cin >> position;	
	while(!fin.eof())
	{
		
		fin.getline(studentinfo, 256);
		cout << studentinfo << endl;
		cout << "What is the position?";
		getToken(studentinfo, position);	
	
	}
	
	fin.close();
	fout.close();
	return 0;

}
int validatefiles()
{
	if(!fin)
	{
		cout << "Error! Input file did not open.";
		return 1;
	}
	if(!fout)
	{
		cout << "Error! Output file did not open.";
		return 1;
	}
	
}
void getToken(char * studentinfo, int position)
{
	char * iterator = studentinfo;
	int count = 0;
	char space = 32; 
	char tab = 9; 
	char array[256];
		
	while(*iterator && count != position)
	{
		if(* iterator == space || * iterator == tab)
			count++;
		do {
			iterator++;
		} while(*iterator && * iterator == space || * iterator == tab);
	}
	cout << "iterator: " << iterator;
//	while(* iterator != delimiter)
//	{
//		array[0] == * iterator;

//	}

	
}



