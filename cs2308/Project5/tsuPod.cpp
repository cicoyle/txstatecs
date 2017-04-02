/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

fstream iostuff;

TsuPod::TsuPod(int mem, int songCount)
{
	cout << "NEW TSUPOD: " << endl;
	memory = mem;
	songs = songCount;
	maxSongs = 25;
	maxMem = 100;
	
}

//initialize tsupod
int TsuPod::initializeTsuPod()
{
	//declare song object
	Song s;

	//open file in binary
	iostuff.open("tsupod_memory.dat", ios::out | ios::in | ios::app | ios::binary);
	
	//validate file
	if(!iostuff)
		return -1;

	//initialize songs
	for(int i = 0; i < songs; i++) {
		iostuff.seekp((i)*sizeof(s)-1, ios::beg);
		iostuff.write(reinterpret_cast<char*>(&s), sizeof(s));
	}

	//close file
	iostuff.close();
	
	return 0;

}

//Add desired song to playlist
int TsuPod::addSong(string title, string artist, int size, int songNumber, int &totalSongs, int &totalMem)
{
	//declare song object
	Song s;

	//temporary char array for title & artist
	char songTitle[256];
	char songArtist[256];

	//open file
	iostuff.open("tsupod_memory.dat", fstream::in | fstream::out | fstream::binary);

	//check that songs does not exceed max songs
	if(maxSongs < songs) {
		cout << "Song not added. Lacks space.";
		return -2;
	}

	//check that size is greater than 0
	if(size < 0){
		cout << "Song not added. Size cannot be smaller than 0" << endl;
		return -3;
	}

	//check that title & artist are not blank
	if(title == " " || artist == " ") {
		cout << "Not added. Song title/artist cannot be blank." << endl;
		return -4;
	}
	
	//increment total of songs
	totalSongs++;
	
	//Calculate total memory
	totalMem = size + totalMem;

	//check if max songs is smaller than song total
	if(maxSongs < totalSongs) {
		cout << "Song not added. There are too many songs." << endl;
		return -5;
	}

	//check if max memory is smaller than total memory
	if(maxMem < totalMem) {
		cout << "Song not added. Not enough memory." << endl;
			return -6;
	}

	//convert string
	strcpy(songTitle, title.c_str());
	strcpy(songArtist, artist.c_str());



	//assign data to object
	s.setTitle(songTitle);
	s.setArtist(songArtist);
	s.setSize(size);
			
	cout << "song title: " << s.getTitle() << endl;


	//write to file
	iostuff.seekp((songNumber)*sizeof(s), iostuff.beg);
	long songPosition = iostuff.tellp();
	cout << "song position: " << songPosition << endl;
	iostuff.write(reinterpret_cast<char*>(&s), sizeof(Song));
	songPosition = iostuff.tellp();
	cout << "to position: " << songPosition << endl;

	//close file
	iostuff.close();
	
	return 0;


}

//Remove desired song to playlist
int TsuPod::removeSong(Song s)
{



}

//Clear the song list
int TsuPod::clearList()
{



}

//Sort the song list alphabetically
int TsuPod::sortList()
{


}

//Dislay the list to the console
void TsuPod::showList()
{	
	//declare song object
	Song s;
	
	cout << "SONGS: " << endl;
	
	//read
	for(int i = 0; i < songs; i++) {
		iostuff.seekg((i)*sizeof(s), iostuff.beg);
		long songPosition = iostuff.tellg();
		cout << "song Position: " << songPosition << endl;
		iostuff.read(reinterpret_cast<char *>(&s), sizeof(s));
		songPosition = iostuff.tellg();
		cout << "to position: " << songPosition << endl;
		cout << "Song #: " << i+1 << " titled: " << s.getTitle();
		cout << " written by: " << s.getArtist() << " size of (MB): " << s.getSize() << endl;
	}
	
	//close file
	iostuff.close();
}

//Display the total memory space left over
int TsuPod::getTotalMem()
{
	return maxMem;

}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem()
{
	
}
