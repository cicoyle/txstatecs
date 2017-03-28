/****************************************************
Name: Cassandra Coyle
Date: 3/24/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "tsuPod.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

fstream iostuff;

TsuPod::TsuPod(int mem, int songcount){
cout << "new tsupod" << endl;
memory = mem;
songs = songcount;
}
//Functions
/*	
25;
"7 Years	Lukas Graham	4";
"Caroline	Amine	3";
"Little Do You Know	Alex & Sierra	2";
"Formation	Beyonce	2";
"Closer	The Chainsmokers	1";
"Fake Love	Drake	4";
"Shape of You	Ed Sheeran	1";
"My Name is	Eminem	2";
"Work from Home	Fifth Harmony	3";
"Never Be Like You	Flume	2";
"I Hate You I Love You	Gnash	5";
"No Role Modelz	J. Cole	2";
"Issues	Julia Michaels	1";
"Panda	Desiigner	3";
"Black Beatles	Rae Sremmurd	5";
"Lost Boy	Ruth B	2";
"Side To Side	Ariana Grande	2";
"Dont Tell Nobody	Tink	1";
"Treat You Better	Shawn Mendez	3";
"Climax	Usher	1";
"Make Me (Cry)	Noah Cyrus	2";
"Play That Song	Train	1";
"Paris	The Chainsmokers	5";
"Starboy	The Weeknd	3";
"Flashlight	The Front Bottoms	2";
*/



//add the songs
int TsuPod::addSong(Song s)
{

iostuff.open("tsupod_memory.dat", ios::out | ios::app | ios::binary);
iostuff << s.getSongTitle() << s.getSongArtist() << s.getSongSize();
iostuff.close();
}

//remove song
int TsuPod::removeSong(Song)
{




}

//clear the song list
int TsuPod::clearSongList()
{



}

//sort the song list
int TsuPod::sortSongList()
{



}

//show the song list
void TsuPod::showSongList()
{



}

//display the total memory
int TsuPod::getTotalMemory()
{

return memory;

}

//shuffle the songs
int TsuPod::shuffleSongs()
{


}

//get the remaining memory usage
int TsuPod::getRemainingMemory()
{



}


