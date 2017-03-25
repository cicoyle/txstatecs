/****************************************************
Name: Cassandra Coyle
Date: 3/24/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
/*********************************
This header file provides the prototypes of the function definitions
for the tsuPod project. This file has to be included in the program that tests the functionality of tsuPod.
You have to create file tsuPod.cpp with function definitions for the test program to work.
*********************************/
#ifndef tsuPod_h
#define tsuPod_h
#include "Song.h"

using namespace std;

class TsuPod
{
	private:
	int maxMem;
	int songCounter;
	int memLeft;

	public:
	//constructors
	TsuPod();


	 //Functions
	int addSong(Song);
	int removeSong(Song);
	int clearSongList();
	int sortSongList();
	void showSongList();
	void showTotalMemory();
	void showRemainingMemory();
	int shuffleSongs();

	//for memory usage
	int getRemainingMem();


};

#endif

