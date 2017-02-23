/*****************************************************
Name:Cassandra Coyle
Date:2/28/17
Problem Number:3
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

char **world;
int height;         //stores the number of rows in the grid
int width;      //stores the number of rows in the grid
void prepass(const char * file)
 {
	ifstream fin(file);
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
	world = new char * [height];

	for(int h = 0; h < height; h++) {
		world[h] = new char [width];
		for(int w = 0; w < width; w++)	{
			fin.get(cell);
			if(cell == 48 || cell == 49)
				*(*(world + h) + w) = cell; 
		}	
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
	for(int h = 0; h < height; h++) 
		for(int w = 0; w < width; w++)	
			cout << getsquare(h,w); 
		
	

}

//This function creats new geneneration grid from the old generation grid
//(add high level description of your implementation logic)
void iterateGeneration ()
{

}

