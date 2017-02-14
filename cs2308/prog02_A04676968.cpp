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
char *getToken(char *studentInfo, int position, char *returnedWord);
void dropGrade(int grade1, int grade2, int grade3, int grade4, int grade5, int grade6);



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
	char *returnedWord = new char[256];
	int position = 0;	//word I'm looking for
	char *firstname;
	char *lastname;
	int ID = 0;
	int grade1 = 0;
	int grade2 = 0;
	int grade3 = 0;
	int grade4 = 0;
	int grade5 = 0;
	int grade6 = -1;
	int grades[6] = {-1};
	//read in and assign words to arrays while not end of file
	while (fin.getline(studentInfo, 256)) {

		firstname = getToken(studentInfo, 0, returnedWord);
		lastname  = getToken(studentInfo, 1, returnedWord);
		ID        = atoi(getToken(studentInfo, 2, returnedWord));
		grades[0]    = atoi(getToken(studentInfo, 3, returnedWord));
		grade1    = atoi(getToken(studentInfo, 3, returnedWord));
		grades[1]    = atoi(getToken(studentInfo, 4, returnedWord));
		grade2    = atoi(getToken(studentInfo, 4, returnedWord));
		grades[2]    = atoi(getToken(studentInfo, 5, returnedWord));
		grade3    = atoi(getToken(studentInfo, 5, returnedWord));
		grades[3]    = atoi(getToken(studentInfo, 6, returnedWord));
		grade4    = atoi(getToken(studentInfo, 6, returnedWord));
		grades[4]    = atoi(getToken(studentInfo, 7, returnedWord));
		grade5    = atoi(getToken(studentInfo, 7, returnedWord));
		grades[5]    = atoi(getToken(studentInfo, 8, returnedWord));
		grade6    = atoi(getToken(studentInfo, 8, returnedWord));



	
		cout << "name: " << getToken(studentInfo, 0, returnedWord) << endl;
		cout << "Lname: " << getToken(studentInfo, 1, returnedWord) << endl;
		cout << "ID: " << ID << endl;
		cout << "g1: " << grade1 << endl;
		cout << "g2: " << grade2 << endl;
		cout << "g3: " << grade3 << endl;
		cout << "g4: " << grade4 << endl;
		cout << "g5: " << grade5 << endl;
		cout << "g6: " << grade6 << endl;

int i;
cout << "loopin biiiiiitch" << endl;
for(i = 0; i < 6; i++)
cout << "grade " << i << " is " << grades[i] << endl;

int min = 100;
for(i = 0; i < 6; i++)
if(grades[i] < min)
min = grades[i];

cout << "lowest: " << min << endl;
		dropGrade(grade1, grade2, grade3, grade4, grade5, grade6);







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
	if (!fin) {
		cout << "Error! Input file did not open.";
		return 1;
	}
	//check that output file opened
	if (!fout) {
		cout << "Error! Output file did not open.";
		return 1;
	}

}

//function get token
char *getToken(char *studentInfo, int position, char *returnedWord)
{
	//variables
	char *iterator = studentInfo;
	int count = 0;		//this is the current word
	char space = 32;
	char tab = 9;
	int singleLetter = 0;
	//do all this at least once while iterator increments and count is not position 
	do {
		//if iterator is a space or tab increment count
		if (*iterator == space || *iterator == tab)
			count++;

		//while iterator is a space or tab increment iterator
		while (*iterator == space || *iterator == tab)
			iterator++;

	} while (*iterator++ && count != position);

	//decrement iterator
	iterator--;

	//set new iterator to current letter
	char *originaltoken = iterator;

	//while iterator is not a space or tab put letters into the returned word array
	while ((*originaltoken != space) && (*originaltoken != tab)) {
		returnedWord[singleLetter++] = *originaltoken;
		originaltoken++;
	}

	//attach the null terminator to end of returned word array
	returnedWord[singleLetter++] = '\0';
	//return returned word array
	return returnedWord;

}


//function dropGrade
void dropGrade(int grade1, int grade2, int grade3, int grade4, int grade5, int grade6)
{
	int lowestGrade = grade1;

	if(grade6 != -1) {
		if(grade2 < lowestGrade)
			lowestGrade = grade2; 
		else if(grade3 < lowestGrade)
			lowestGrade = grade3;
		else if(grade4 < lowestGrade)
			lowestGrade = grade4;
		else if(grade5 < lowestGrade)
			lowestGrade = grade5;
		else if(grade6 < lowestGrade)
			lowestGrade = grade6;
	}
	else
		grade6 = 0;
	cout << "lowest: " << lowestGrade << endl;



}

