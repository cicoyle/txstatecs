/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 60
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
	int currentMem;
	int  songs;
	int currentSong;
	int memoryLeft;
	int * prefixSum;

	void updatePrefixSum(int, int);
	int lengthOf(int);
	int getPrefixSum(int);
	int insertSong(Song, int);
	void printPrefixSum();

	public:
	//Constructor
	TsuPod(int mem, int songCount);

	//Functions
	int initializeTsuPod();
	int validateAddSong(string t, string a, int si, int currentMem);
	int addSong(string t, string a, int si, int);
	int removeSong(string, string, int);
	Song getWholeSong(int);
	int getRandomNum();
	int clearList();
	int sortList();
	void showList();
	int getTotalMem();
	int shuffle();
	int getRemainingMem(int);
};

#endif
