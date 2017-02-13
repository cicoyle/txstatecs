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
char * getToken(char * studentinfo, int position, char * returnedWord);

ifstream fin;
ofstream fout;

int main()
{
	fin.open("student_input.dat");
	fout.open("student_results.dat");
	validatefiles();
	//variables 
	char studentinfo[256];
	char * returnedWord = new char[256];
	int position = 0;	
	while(!fin.eof())
	{
		
		fin.getline(studentinfo, 256);
		cout << studentinfo << endl;
		cout << "What is the position?";
		cin >> position;	
		getToken(studentinfo, position, returnedWord);	
	
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
char * getToken(char * studentinfo, int position, char * returnedWord)
{
	char * iterator = studentinfo;
	int count = 0;
	char space = 32; 
	char tab = 9; 
	int singleLetter = 0;		
	do {

		if(* iterator == space || * iterator == tab)
			count++;
		
		while(* iterator == space || * iterator == tab)
			iterator++;
	} while(* iterator++ && count != position);
	iterator--;
	char * originaltoken = iterator;
	while((* originaltoken != space) && (* originaltoken != tab))
	{
		returnedWord[singleLetter++] = * originaltoken;
		originaltoken++;
	}
	returnedWord[singleLetter++] = '\0';
	cout << "HITHER: " << returnedWord << endl;
	return returnedWord;
	
}



