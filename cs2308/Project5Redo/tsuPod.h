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
#include <string>
#include <fstream>

using namespace std;

class TsuPod {
	private:
		int maxSize;
		int NumberOfSongs;
		Song song;
		fstream iostuff;
	public:
		TsuPod();
		TsuPod(int currentMaxSize, int currentNumberOfSongs);
		int initializeTsuPod();
		int addSong(string t, string a, int size, int songNumber,
		            int &memTotal, int &songTotal);
		int showList();
		int sortList(int songTotal);
		int removeSong(string t, string a, int size, int songNumber, 
				int &memTotal, int &songTotal);
		int getMemTotal() const;
		int getNumSongs() const;
		int getRemainingMemory(int memTotal) const;
		int clearList();
		int closeFile();
};

#endif 
