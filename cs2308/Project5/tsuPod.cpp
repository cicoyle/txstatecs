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


//Add desired song to playlist
int TsuPod::addSong(Song s)
{
	iostuff.open("tsupod_memory.dat", ios::out | ios::app | ios::binary);

	iostuff.write(reinterpret_cast<char*>(&s), sizeof(s));
	iostuff.seekg(0L, ios::beg);
	
	iostuff.close();

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
	Song s;
	for(int i = 0; i < songs; i++)
		cout << "READ: " << iostuff.read(reinterpret_cast<char*>(&s), sizeof(s)) << endl;

}

//Display the total memory space left over
void TsuPod::getTotalMem()
{


}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

}

//Get the remaining memory space left over
int TsuPod::getRemainingMem()
{

}
