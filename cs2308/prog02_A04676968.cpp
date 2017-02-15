/**********************************
Name: Cassandra Coyle
Date: 2/14/17
Problem Number: 02
Hours spent solving the problem: 10
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
int detectError(int grades[], int grade6);
int findLowestGrade(int grades[]);
double getAverage(int grade1, int grade2, int grade3, int grade4, int grade5, int grade6, int lowestGrade);
char convertAverageToLetterGrade(double average);

ifstream fin;
ofstream fout;

//declare grade count globally
int Acount = 0;
int Bcount = 0;
int Ccount = 0;
int Dcount = 0;

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
	int grade6 = 999;
	int grades[6] = {0};
	int lowestGrade = 0;
	double average = 0.0;
	char letterGrade;
	
	//print header for output file	
	fout << setw(15) << "Last_name" << setw(15) << "First_name" << setw(15) << "ID";
	fout << setw(15) << "Average_Score" << setw(15) << "Grade" << endl << endl;

	//read in and assign words to arrays while not end of file
	while (fin.getline(studentInfo, 256)) {

		firstname = getToken(studentInfo, 0, returnedWord);
		lastname  = getToken(studentInfo, 1, returnedWord);
		ID        = atoi(getToken(studentInfo, 2, returnedWord));
		grades[0] = atoi(getToken(studentInfo, 3, returnedWord));
		grade1    = atoi(getToken(studentInfo, 3, returnedWord));
		grades[1] = atoi(getToken(studentInfo, 4, returnedWord));
		grade2    = atoi(getToken(studentInfo, 4, returnedWord));
		grades[2] = atoi(getToken(studentInfo, 5, returnedWord));
		grade3    = atoi(getToken(studentInfo, 5, returnedWord));
		grades[3] = atoi(getToken(studentInfo, 6, returnedWord));
		grade4    = atoi(getToken(studentInfo, 6, returnedWord));
		grades[4] = atoi(getToken(studentInfo, 7, returnedWord));
		grade5    = atoi(getToken(studentInfo, 7, returnedWord));
		grades[5] = atoi(getToken(studentInfo, 8, returnedWord));
		grade6    = atoi(getToken(studentInfo, 8, returnedWord));

		//call detect error function
		detectError(grades, grade6);

		//call find lowest grade function
		lowestGrade = findLowestGrade(grades);

		//call get average function
		average = getAverage(grade1, grade2, grade3, grade4, grade5, grade6, lowestGrade);
		
		//call convert average to letter grade function
		letterGrade = convertAverageToLetterGrade(average);

		//print data to output
		fout << setw(15) << getToken(studentInfo, 1, returnedWord);
		fout << setw(15) << getToken(studentInfo, 0, returnedWord);
		fout << setw(15) << ID << setw(15) << fixed << showpoint << setprecision(1) << average;
		fout << setw(15) << letterGrade << endl;
	}

	//print grade count to output file
	fout << endl << endl;
	fout << setw(15) << "\tGrade Totals:\n\n";
	fout << setw(15) << "A - " << Acount << endl;
	fout << setw(15) << "B - " << Bcount << endl;
	fout << setw(15) << "C - " << Ccount << endl;
	fout << setw(15) << "D - " << Dcount << endl;

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

//function to detect errors
int detectError(int grades[], int grade6)
{	
	//if statement to see if there is a grade 6
	if(grade6 == 999) {
		cout << "Warning. There are only 5 grades." << endl;
		return 0;
	}

	//if statement to check if there are negative grades
	for(int i = 0; i < 6; i++) {
		if(grades[i] < 0) {
			cout << "Error. A negative grade is present." << endl;
			return -1;
		}
		else
			return 0;
	}
}

//function dropGrade
int findLowestGrade(int grades[])
{
	int lowestGrade = 100;

	//assign lowest grade in array to lowest grade
	for(int i = 0; i < 6; i++) {
		if(grades[i] < lowestGrade)
			lowestGrade = grades[i];
	}

	return lowestGrade;
}

//function get average
double getAverage(int grade1, int grade2, int grade3, int grade4, int grade5, int grade6, int lowestGrade)
{
	double average = 0.0;
	
	//calculate average if there are 6 grades
	if(grade6 != 999) 
		average = ((grade1 + grade2 + grade3 + grade4 + grade5 + grade6)/6.0);

	//calculate average if there only 5 grades
	else if(grade6 = 999)
		average = ((grade1 + grade2 + grade3 + grade4 + grade5)/5.0);

	return average;
}

//functiong to convert average to letter grade
char convertAverageToLetterGrade(double average)
{
	char letterGrade;	
	
	//use if and else if statement to determine lettergrade
	//increment that lettergrade count	
	if(average >= 89.5) {
		letterGrade = 'A';
		Acount++;
	}

	else if(average >= 79.5) {
		letterGrade = 'B';
		Bcount++;
	}

	else if(average >= 69.5) {
		letterGrade = 'C';
		Ccount++;
	}

	else if(average >= 59.5) {
		letterGrade = 'D';
		Dcount++;
	}
		
	return letterGrade;
}

