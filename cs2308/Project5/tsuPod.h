/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#ifndef tsuPod_h
#define tsuPod_h
#include "Song.h"

using namespace std;

class TsuPod
{
	private:
	int memory;
	int maxMem;
	int  songs;
	int songCount;
	int memoryLeft;
	int maxSongs;
	public:
	//Constructor
	TsuPod(int mem, int songCount);

	//Functions
	int initializeTsuPod();
	int addSong(string t, string a, int s, int songNumber, int &totalSong, int &totalMem);
	int removeSong(Song s);
	int clearList();
	int sortList();
	void showList();
	int getTotalMem();
	int shuffle();
	int getRemainingMem();
};

#endif
