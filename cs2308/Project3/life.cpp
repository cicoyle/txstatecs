/*****************************************************
Name:Cassandra Coyle
Date:2/28/17
Problem Number:3
Hours spent on project: 13
CS2308
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.


#include <iostream>
#include <fstream>
#include <cstdio>
#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ** NeighborCount;
char **world;
int height;         //stores the number of rows in the grid
int width;      //stores the number of rows in the grid
void prepass(const char * file)
 {
	ifstream fin;
	fin.open(file);

	if(!fin)
		cout << "Error. Input file did not open.";

	char cell;
	while(fin.get(cell)) {
		if(cell == 48 || cell == 49)
		width++;
		if(cell == '\n')
			height++;
	}

	width/=height;
	fin.close();
}

int count(int row, int column)
{
	int counter = 0;
	for(int h = (row-1); h <= (row+1); h++) 
		for(int w = (column-1); w <= (column+1); w++) 
			if( * ( * ( world + h) + w) == 49)
				counter += 1;
			
		
	

	if( * ( * ( world + row) + column) == 49)
		counter -= 1;

	return counter;

}

void countNeighbors()
{
	for (int row = 1; row < (height+1); row++) { 
		for (int column = 1; column < (width+1); column++) {
			* ( * (NeighborCount + row) + column) = count(row, column);
			cout << * ( * (NeighborCount + row) + column);
		}
	cout << endl;
	}
		
}

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void populateWorld (const char * file)
{

	height = 0;
	width = 0;

	prepass(file);

cout << height << endl << width << endl;	
	ifstream fin;

	fin.open(file);

	if(!fin) 
		cout << "Error. Input file did not open.";

	char cell;	    
	world = new char * [height+2];
	NeighborCount = new int * [height+2];

	for(int h = 0; h < (height+2); h++) { 
		world[h] = new char [width+2];
		NeighborCount[h] = new int [width+2];
	}
	
	for(int h = 0; h < (height+2); h++) {
		for(int w = 0; w < (width+2); w++) {	
			* ( * (world + h) + w) = 0;
			* ( * (NeighborCount + h) + w) = 0;
		}
	}

	for(int h = 1; h < (height+1); h++) {
		for(int w = 1; w < (width+1); w++)	{
			fin.get(cell);
			if(cell == 48 || cell == 49)  
				*(*(world + h) + w) = cell;
		}
	fin.ignore();	
	}
fin.close();

}

char getsquare(int height, int width) {
	return *(*(world + height) + width); 
}
	
//This function outputs the grid for current generation (add high level 
//description of your implementation logic) 
void showWorld ()
{	
	cout << endl;
	for(int h = 1; h < (height+2); h++) {
		for(int w = 1; w < (width+2); w++) {	
			cout << getsquare(h,w); 		
		}
	cout << endl;
	}
cout << "width : " << width << endl << "height: " << height << endl;
	
	countNeighbors();
	
}

void DeadOrAlive(int ** NewGen)
{

	for(int h = 1; h < (height+1); h++) {  
		for(int w = 1; w < (width+1); w++) { 
	if( * ( * (world + h) + w) == 49 && * ( * (NeighborCount + h) + w) <= 1)
		* ( * (NewGen + h) + w) = 0;
	if(( * ( * (world + h) + w) == 49) && ( * ( * (NeighborCount + h) + w) == 2 ||
	    (* ( * (NeighborCount + h) + w) == 3)))
		* ( * (NewGen + h) + w) = 1;
	if( * ( * (world + h) + w) == 49 && * ( * (NeighborCount + h) + w) >= 4)
		* ( * (NewGen + h) + w) = 0;
	if( * ( * (world + h) + w) == 48 && * ( * (NeighborCount + h) + w) == 3)
		* ( * (NewGen + h) + w) = 1;
		}
	}

}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{

	int ** NewGen;
	NewGen = new int * [height+2];
		
	for(int h = 0; h < (height+2); h++)
		NewGen[h] = new int [width+2];

	for(int h = 0; h < (height+2); h++) 
		for(int w = 0; w < (width+2); w++) 	
			* ( * (NewGen + h) + w) = 0;
	
	DeadOrAlive(NewGen);


	for(int h = 0; h < (height+2); h++) {
		for(int w = 0; w < (width+2); w++) {
			cout << * ( * (NewGen + h) + w);	
		}	
	cout << endl;
	}





}

