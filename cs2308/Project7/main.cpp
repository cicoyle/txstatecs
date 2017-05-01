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
	if(!fin) {
		cout << "Error. Input file did not open." << endl;
		return -1;
	}
	
	cout << "Enter valid input file name:  ";
	cin >> fileName;
//	ofstream fout;
	fin.open(fileName.c_str());

	string tempVar;
	char * fileLine;		
	

//	fin.open(fileName.c_str());
//	fout.open("exp_output.dat");

//	stack.checkInputFile();

	while(getline(fin, tempVar)) { 
		
		int len = tempVar.length();
		fileLine = new char[len];
	
		strcpy(fileLine, tempVar.c_str());
		
		bool retCode = stack.checkSpecialCase(fileLine);
		
		if(retCode == false)
			fout << " === missing: " << endl;
		else
			fout << "=== valide expression" << endl;
//		fout << fileLine;
//		if(stack.checkSpecialCase(fileLine) == true) { 
//			fout << " === valid expression " << endl;
//		}
	
//		else if(stack.checkSpecialCase(fileLine) != true) {
//			fout << "missing: " << endl;
//		}
			
	}
	fout.close();
	fin.close();
	return 0;
}

