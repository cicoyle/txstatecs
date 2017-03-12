/*****************************************************
Name: Cassandra Coyle
Date: 3/12/17
Problem Number: 4
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "tsuPod.h"

using namespace std;

//declare variables globally
const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

//function initialize tsupod
void initTsuPod()
{
	//create struct
	struct TsuPod
	{
	   string title;
	   string artist;
	   int size;
	};
	
	//create instance
	TsuPod tsuPod[NUM_SONGS];
	
	//initialize
	for(int i = 0; i < NUM_SONGS; i++) {
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;
     	}
  
}

//function to add song
int addSong (/*add nessesary parameters here,*/ string newTitle, string newArtist, int size)
{


}

//function to remove song
int removeSong (/*add nessesary parameters here,*/ string title)
{


}

//function to clear memory
void clearMemory(/*add nessesary parameters here*/)
{


}

//function to display song list
void showSongList (/*add nessesary parameters here*/)
{


}

//function to shuffle songs
void shuffle (/*add nessesary parameters here*/)
{


}


