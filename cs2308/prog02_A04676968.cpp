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
char * getToken(char * studentInfo, int position, char * returnedWord);

ifstream fin;
ofstream fout;

int main()
{
	//open files
	fin.open("student_input.dat");
	fout.open("student_results.dat");
	//call validatefiles to check that files opened
	validatefiles();
	//variables 
	char studentInfo[256];
	char * returnedWord = new char[256];
	int position = 0; //word I'm looking for
	char firstname[11];
	char lastname[13];
	int ID = 0;
	int grade1 = 0;
	int grade2 = 0;
	int grade3 = 0;
	int grade4 = 0;
	int grade5 = 0;
	int grade6 = 0;


	//read in and assign words to arrays while not end of file
	while(!fin.eof())
	{
		
		fin.getline(studentInfo, 256);
		cout << studentInfo << endl;	
		
		firstname =      getToken(studentInfo, 0, returnedWord);	
		lastname  =      getToken(studentInfo, 1, returnedWord);	
		ID        = atoi(getToken(studentInfo, 2, returnedWord));	
		grade1    = atoi(getToken(studentInfo, 3, returnedWord));	
		grade2    = atoi(getToken(studentInfo, 4, returnedWord));	
		grade3    = atoi(getToken(studentInfo, 5, returnedWord));	
		grade4    = atoi(getToken(studentInfo, 6, returnedWord));	
		grade5    = atoi(getToken(studentInfo, 7, returnedWord));	
		grade6    = atoi(getToken(studentInfo, 8, returnedWord));	
	}
	//close files
	fin.close();
	fout.close();
	return 0;

}
//function validate files
int validatefiles()
{	
	//check that input file opened
	if(!fin)
	{
		cout << "Error! Input file did not open.";
		return 1;
	}
	//check that output file opened
	if(!fout)
	{
		cout << "Error! Output file did not open.";
		return 1;
	}
	
}
//function get token
char * getToken(char * studentInfo, int position, char * returnedWord)
{	
	//variables
	char * iterator = studentInfo;
	int count = 0; //this is the current word
	char space = 32; 
	char tab = 9; 
	int singleLetter = 0;
	//do all this at least once while iterator increments and count	is not position	
	do {
		//if iterator is a space or tab increment count
		if(* iterator == space || * iterator == tab)
			count++;
		//while iterator is a space or tab increment iterator
		while(* iterator == space || * iterator == tab)
			iterator++;
	} while(* iterator++ && count != position);
	//decrement iterator
	iterator--;
	//set new iterator to current letter
	char * originaltoken = iterator;
	//while iterator is not a space or tab put letters into the returned word array
	while((* originaltoken != space) && (* originaltoken != tab))
	{
		returnedWord[singleLetter++] = * originaltoken;
		originaltoken++;

	}
	//attach the null terminator to end of returned word array
	returnedWord[singleLetter++] = '\0';
	//return returned word array
	return returnedWord;
	
}



