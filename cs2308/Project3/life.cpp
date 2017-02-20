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

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of rows in the grid

//This function reads input file for subsequent prosessing (add high level 
//description of your implementation logic) 
void populateWorld (const char * file)
{
	ifstream fin;
	fin.open("glider_gun_fight.txt");
	int *array;	
	if(!fin) 
		cout << "Error. Input file did not open.";

	while(!fin.eof()) {
		while(fin)
			COLUMNS++;
	ROWS++;
//	array = new int *[ROWS];
//	for(int row = 0; row < ROWS; row++)
//		array[row] = new int[COLUMNS];
	}

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

