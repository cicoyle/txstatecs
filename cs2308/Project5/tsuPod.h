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
	int songCounter;
	int memoryLeft;
	int maxSongs;
	public:
	//Constructor
	TsuPod(int mem, int songCount);

	//Functions
	int initializeTsuPod();
	int addSong(string t, string a, int s, int songCount, int &totalSong, int &totalMem);
	int removeSong(Song s);
	int clearList();
	int sortList();
	void showList();
	void getTotalMem();
	int shuffle();
	int getRemainingMem();
};

#endif
