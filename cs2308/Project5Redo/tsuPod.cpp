/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "tsuPod.h"

using namespace std;

//constructor (default)
TsuPod::TsuPod() {
	maxSize = 0;
	NumberOfSongs = 0;
}

//constructor
TsuPod::TsuPod(int currentMaxSize, int currentNumberOfSongs) {
	maxSize = currentMaxSize;
	NumberOfSongs = currentNumberOfSongs;
}

//initialize function
int TsuPod::initializeTsuPod() {
	//declare song object
	Song s;	

	//open file
	iostuff.open("tsupod_memory.dat", ios::in | ios::out | ios::binary);	

	//validate that file opened
	if(!iostuff)				
		return -1;

	//initialize
	for(int i = 0; i < NumberOfSongs; i++) {
		iostuff.seekp((i)*sizeof(s), ios::beg);
		iostuff.write(reinterpret_cast<char *>(&s), sizeof(s));
	}

	return 0;
}

//add song function
int TsuPod::addSong(string t, string a, int size, int songNumber, int &memTotal, int &songTotal) {
	//declare song object
	Song s;		

	//arrays
	char songT[256];						
	char songA[256];

	//check that title and artist are not blank
	if(t == " " || a == " ") {
		cout << "Error. Song not added. Title/Artist can't be blank." << endl;
		return -4;
	}

	//check that size is not negative
	if(size < 0) {
		cout << "Error. Song not added. Size has to be greater than 0." << endl;
		return -2;
	}

	//check song number
	if(NumberOfSongs < songNumber) {
		cout << "Error. Song not added. Too many songs." << endl;
		return -3;
	}

	//increment song total
	songTotal++;	

	//check song number
	if(NumberOfSongs < songTotal) {
		cout << "Error. Song not added. Could not add song(s). Too many songs." << endl;
		songTotal--;
		return -3;
	}

	//calculate memory total
	memTotal = size + memTotal;

	//check memory
	if(maxSize < memTotal) {
		cout << "Error. Song not added. Not enough memory." << endl;
		memTotal + memTotal - size;	
		songTotal--;
		return -2;
	}

	//get string copy
	strcpy(songT, t.c_str());
	strcpy(songA, a.c_str());

	//assign song title, artist, size, song number
	s.setTitle(songT);
	s.setArtist(songA);
	s.setSize(size);
	s.setPosition(songNumber);

	//seek and write to file
	iostuff.seekp((songNumber - 1)*sizeof(s), ios::beg);
	iostuff.write(reinterpret_cast<char *>(&s), sizeof(s));	
	iostuff.seekp(0L, ios::beg);

	return 0;
}

//remove song function
int TsuPod::removeSong(string t, string a, int size, int songNumber, int &memTotal, int &songTotal) {
	//declare song object
	Song s;

	//decrement song total
	songTotal--;

	//calculate mem total
	memTotal = memTotal - size;

	if(0 > memTotal) {
		songTotal++;
		memTotal = size + memTotal;
		cout << "Memory total cannot be negative.";
		return -1;
	}

	//assign title, artist, size
	t = "EMPTY";	
	a = "EMPTY";
	size = 0;

	//arrays
	char songT[256];
	char songA[256];

	//get string copy
	strcpy(songT, t.c_str());
	strcpy(songA, a.c_str());

	//assign title, artist, size
	s.setTitle(songT);
	s.setArtist(songA);
	s.setSize(size);
	
	//seek and write to file
	iostuff.seekp((songNumber - 1)*sizeof(s), ios::beg);
	iostuff.write(reinterpret_cast<char *>(&s), sizeof(s));
	iostuff.seekp(0L, ios::beg);

	return 0;
}

//show song function
int TsuPod::showList() {
	//declare song object
	Song s;	

	cout << "Show Song List: " << endl;

	//show songs in file
	for(int index = 0; index < NumberOfSongs; index++) {
		iostuff.seekg((index)*sizeof(s), ios::beg);
		iostuff.read(reinterpret_cast<char *>(&s), sizeof(s));
		cout << "Song " << (index + 1) << ": " << s.getTitle() << "  by " 
		     << s.getArtist() << " Size of: " << s.getSize() << "MB" << endl;
	}

	cout << endl;

	iostuff.clear();
	iostuff.seekg(0L, ios::beg);

	return 0;
}

//sort list function
int TsuPod::sortList(int songTotal) {
	//declare song objects
	Song s1;
	Song s2;
	Song sTemp;
	Song sBlank;

	bool swap = 1;

	//read in songs
	for(int index = 0; index < songTotal; index++) {
		iostuff.seekg((index)*sizeof(s1), ios::beg);
		iostuff.read(reinterpret_cast<char *>(&s1), sizeof(s1));
		for(int i = index + 1; i < (songTotal + 1); i++) {
			iostuff.seekg((i)*sizeof(s2), ios::beg);
			iostuff.read(reinterpret_cast<char *>(&s2), sizeof(s2));
			if(s1 > s2){
				if(s2 != sBlank) {
					sTemp = s1;
					s1 = s2;
					s2 = sTemp;
					iostuff.seekp((i)*sizeof(s2), ios::beg);
					iostuff.write(reinterpret_cast<char *>(&s2), sizeof(s2));
					swap = 1;
				}
			}
			else if(s1 < s2) 
				swap = 0;
			else if(s1 == s2)
				swap = 0;
		}
		iostuff.seekp((index)*sizeof(s1), ios::beg);
		iostuff.write(reinterpret_cast<char *>(&s1), sizeof(s1));
	}

	return 0;
}

//get max size
int TsuPod::getMemTotal() const {
	return maxSize;
}

//get number of songs
int TsuPod::getNumSongs() const {
	return NumberOfSongs;
}

//get remaining memory
int TsuPod::getRemainingMemory(int memTotal) const {
	return memTotal;
}

//clear song list function
int TsuPod::clearList() {
	//declare song object
	Song s;	

	//clear songs
	for(int index = 0; index < NumberOfSongs; index++) {
		iostuff.seekp((index)*sizeof(s), ios::beg);
		iostuff.write(reinterpret_cast<char *>(&s), sizeof(s));
	}

	return 0;
}

//close file
int TsuPod::closeFile() {
	//close file
	iostuff.close();
	return 0;
}
