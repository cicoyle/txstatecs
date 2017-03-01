/****************************************************
Name: Cassandra Coyle
Date: 3/1/2017
Problem Number: 3
CS2308
Hours worked on project: 19
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
char ** world;	  //store world
int ** NeighborCountGrid;	  //store neighborcount

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 

void prepass(const char * file)
{
	//open files
	ifstream fin;
	fin.open(file);
	
	//variable
	char cell;

	//validate
	if(!fin)
		cout << "Error. Input file did not open." << endl;

	//count rows and columns
	while(fin.get(cell))
	{
		if(cell == 48 || cell == 49)
			COLUMNS++;
		if(cell == '\n')
			ROWS++;
	}
	
	//calculate columns
	COLUMNS/=ROWS;
	cout << "ROWS: " << ROWS << " COLUMNS: " << COLUMNS << endl;
	
	//Close file
	fin.close();
}

int Count(int ro, int co)
{
	//initialize neighbor count
	int neighbor = 0;	

	//Upper left
	if( *(* (world + (ro - 1)) + (co - 1)) == 49)
		neighbor++;

	//Left
	if( *(* (world + ro) + (co - 1)) == 49)
		neighbor++;
	
	//Bottom left
	if( *(* (world + (ro + 1)) + (co - 1)) == 49)
		neighbor++;
	
	//Under
	if( *(* (world + (ro + 1)) + co) == 49)
		neighbor++;

	//Bottom right
	if( *(* (world + (ro + 1)) + (co + 1)) == 49)
		neighbor++;

	//Right
	if( *(* (world + ro) + (co + 1)) == 49)
		neighbor++;

	//Right upper
	if( *(* (world + (ro - 1)) + (co + 1)) == 49)
		neighbor++;

	//Above
	if( *(* (world + (ro - 1)) + co) == 49)
		neighbor++;

	//return total neighbor count
	return neighbor;
}

void countNeighbors()
{
	cout << "NeighborCountGrid" << endl;
	
	//count neighbors and output
	for(int r = 1; r < (ROWS + 1); r++) {
		for(int c = 1; c < (COLUMNS + 1); c++) {
			*(* (NeighborCountGrid + r) + c) = Count(r,c);
			cout << *(* (NeighborCountGrid + r) + c);
		}
		cout << endl;
	}
}

void populateWorld (const char * file)
{
	//Initialize variables
	ROWS = 0;
	COLUMNS = 0;
	char cell;
	ifstream fin;//make file object

	//Read in grid
	prepass(file);

	//Open file
	fin.open(file);

	//If file doesn't open give error
	if(!fin)
		cout << "Error. Input File did not open." << endl;


	//Make memory for my world
	world = new char * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		world[row] = new char [COLUMNS + 2];

	//Initialize memory for my world
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (world + row) + col) = 48;

	//Make memory for NeighborCountGrid
	NeighborCountGrid = new int * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		NeighborCountGrid[row] = new int [COLUMNS + 2];

	//Initialize NeighborCountGrid to zero
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (world + row) + col) = 0;

	//Read in world values
	for(int row = 1; row < ROWS + 1; row++)
	{
		for(int col = 1; col < COLUMNS + 1; col++)
		{
			fin.get(cell);
			
			//If 1 or 0 read in value
			if(cell == 48 || cell == 49)
				*(* (world + row) + col) = cell;
		}
		fin.ignore();
	}
	fin.close();
}

//This fucttion outputs the grid for current generation 
void showWorld ()
{
	cout << "World: " << endl;

	//show content for every row and column
	//keep in mind buffer of zeros around world
	for(int r = 1; r < ROWS + 1; r++) {
		for(int c = 1; c < COLUMNS + 1; c++) {
			cout << *(* (world + r) + c);
		}
		cout << endl;
	}
	
}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{
	//Count neighbors
	countNeighbors();

	//Create and allocate memory for next generation
	char ** newgen;
	newgen = new char * [ROWS + 2];
	for(int row = 0; row < ROWS + 2; row++)
		newgen[row] = new char [COLUMNS + 2];
	
	//Initialize next generation
	for(int row = 0; row < ROWS + 2; row++)
		for(int col = 0; col < COLUMNS + 2; col++)
			*(* (newgen + row) + col) = 48;

	//For every organism, check if next generation organism becomes alive/dead
	for(int row = 1; row < ROWS + 1; row++) {
		for(int col = 1; col < COLUMNS + 1; col++) {
			//Rule one: alive if world was dead with NeighborCountGrid is 3
			if( (*(* (world + row) + col) == 48) && (*(* (NeighborCountGrid + row) + col) == 3))
				*(* (newgen + row) + col) = 49;

			//Rule two: dead if NeighborCountGrid is 4 or more
			if( (*(* (world + row) + col) == 49) && (*(* (NeighborCountGrid + row) + col) >= 4))
				*(* (newgen + row) + col) = 48;
	
			//Rule three: dead if NeighborCountGrid is one or fewer
			if( (*(* (world + row) + col) == 49) && (*(* (NeighborCountGrid + row) + col) < 2))
				*(* (newgen + row) + col) = 48;

			//Rule four: alive if NeighborCountGrid is 2 or more
			if( (*(*(world + row) + col) == 49) &&
			 (( *(* (NeighborCountGrid + row) + col) == 2) ||
			 (*(* (NeighborCountGrid + row) + col) == 3)))
				*(* (newgen + row) + col) = 49;		
		}
	}	

	cout << "Next Gen: " << endl;
	for(int r = 1; r < ROWS+1; r++) {
		for(int c = 1; c < COLUMNS+1; c++) {
			cout << *(*(newgen+r)+c);
		}
		cout << endl;
	}

	delete world;
	world = newgen;
}		

