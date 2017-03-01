/***************************************************
me: Cassandra Coyle
Date:3/1/17
Problem Number:3
Hours spent solving problem: 20
CS2308
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.


#include <iostream>
#include <fstream>

#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of rows in the grid
int ** NeighborCount;
char **world;

//function counts rows and columns in file
void prepass(const char * file)
 {
	//open file
	ifstream fin;
	fin.open(file);

	//validate file
	if(!fin)
		cout << "Error. Input file did not open.";

	//variable
	char cell;

	//check if cell is a 0 or 1 or newline
	while(fin.get(cell)) {
		if(cell == 48 || cell == 49)
		COLUMNS++;
		if(cell == '\n')
			ROWS++;
	}

	//calculate columns
	COLUMNS/=ROWS;
cout << "COLUMNS: " << COLUMNS << " ROWS: " << ROWS << endl;

	//close file
	fin.close();
}
//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void populateWorld (const char * file)
{
	//initialize rows and columns
	ROWS = 0;
	COLUMNS = 0;
	
	//call prepass
	prepass(file);

	//open file
	ifstream fin;
	fin.open(file);

	//validate
	if(!fin) 
		cout << "Error. Input file did not open.";

	//variable
	char cell;
	
	//allocate memory for world and neighborcount	    
	world = new char * [ROWS];
	NeighborCount = new int * [ROWS+2];

	for(int r = 0; r < (ROWS); r++)  
		world[r] = new char [COLUMNS];

	for(int r = 0; r < (ROWS+2); r++)  
		NeighborCount[r] = new int [COLUMNS+2];
	
	//initalize world
	cout << "initialized world: " << endl;
	for(int r = 0; r < ROWS; r++) {
		for(int c = 0; c < COLUMNS; c++) {
			* ( * (world + r) + c) = 48;
	cout << * ( * (world + r) + c);
		}
	cout << endl;
	}

	//initialize neighborcount
	cout << "Initialized Neighborcount: " << endl;
	for(int r = 0; r < (ROWS+2); r++) { 
		for(int c = 0; c < (COLUMNS+2); c++) {	
			* ( * (NeighborCount + r) + c) = 0;
		cout << * ( * (NeighborCount + r) + c);
		}
	cout << endl;
	}
	
	//assign world
	cout << "WORLD: " << endl;
	for(int r = 0; r < ROWS; r++) {
		for(int c = 0; c < COLUMNS; c++) {
			fin.get(cell);
			if(cell == 48 || cell == 49)  
				*(*(world + r) + c) = cell;
		cout << *(*(world+r)+c);
		}
	fin.ignore();
	cout << endl;	
	}

	//close file
	fin.close();
}

//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{

}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{

}

