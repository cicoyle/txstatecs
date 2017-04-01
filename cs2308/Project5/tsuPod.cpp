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
	
}

//initialize tsupod
int TsuPod::initializeTsuPod()
{
	//declare song object
	Song s;

	//open file in binary
	iostuff.open("tsupod_memory.dat", ios::out | ios::app | ios::binary);
	
	//validate file
	if(!iostuff)
		return -1;

	//initialize songs
	for(int i = 0; i < songs; i++) {
		iostuff.seekp((i)*sizeof(s), ios::beg);
		iostuff.write(reinterpret_cast<char*>(&s), sizeof(s));
	}

//totalSongs++;



//s.setTitle(t);
//s.setArtist(a);
//s.setSize(s);







	//close file
	iostuff.close();
	
	return 0;

}

//Add desired song to playlist
int TsuPod::addSong(string t, string a, int s, int songCount, int &totalSongs, int &totalMem)
{
	cout << "Song " << songCount << ": " << t << " by " << a << " size: " <<  s << endl;
	//if(songCount > songs)
	//	return -2;
	if(s < 0){
		cout << "Size cannot be smaller than 0" << endl;
		return -3;
	}
	if(t == "EMPTY" || a == "EMPTY") {
		cout << "Not added. Song title/artist cannot be blank." << endl;
		return -4;
	}
	

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
	
	cout << "SONGS: " << endl;

	for(int i = 0; i < songs; i++) {
		iostuff.seekg((i)*sizeof(s), ios::beg);
		iostuff.read((char *)&s, sizeof(s));
	}
cout << "title: " << s.getTitle() << endl;

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
