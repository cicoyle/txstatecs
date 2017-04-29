/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include "charStack.h"
#include <cstring>

using namespace std;

int main() {
	charStack stack(300);
	
	ifstream fin;
	ofstream fout;

	string fileName;
	string tempVar;
	char * fileLine;		
	
	cout << "Enter valid input file name:  ";
	cin >> fileName;

	fin.open(fileName.c_str());
	fout.open("exp_output.dat");

	if(!fin) {
		cout << "Error. Input file did not open." << endl;
		return -1;
	}

	if(!fout) {
		cout << "Error. Output file did not open." << endl;
		return -1;
	}
	while(getline(fin, tempVar)) { 
		
		int len = tempVar.length();
		fileLine = new char[len];
	
		strcpy(fileLine, tempVar.c_str());
		
		fout << fileLine;
		if(stack.checkSpecialCase(fileLine) == true) 
			fout << " === valid expression " << endl;
		else if(stack.checkSpecialCase(fileLine) == false) 
			fout << " === missing: " << endl;
	
	}

	return 0;
}

