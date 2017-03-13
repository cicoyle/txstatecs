/*****************************************************
Name: Cassandra Coyle
Date: 3/12/17
Problem Number: 4
Hours spent solving the problem: 8
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

//declare variables globally
const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

	//create struct
	struct TsuPod
	{
	   string title;
	   string artist;
	   int size;
	};
	
	//create instance
	TsuPod tsuPod[NUM_SONGS];

//function initialize tsupod
void initTsuPod()
{
	//initialize
	for(int i = 0; i < NUM_SONGS; i++) {
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;
  	}
}

//function to add song
int addSong (string newTitle, string newArtist, int size)
{
	//initalize variables
	 int i = 0;
    	 int memory = 0;
   	 int total = 0;

	//calculate total memory    
	for(int i = 0; i < NUM_SONGS; i++)
		total += tsuPod[i].size;
	
	memory = MEMORY_SIZE - total;
 	
	//if size is bigger than memor
	if(size > memory)
		return -1;
	
	//assign songs
	while(i < NUM_SONGS)
    	{
           if (tsuPod[i].size > 0)
              	i++;
           else {
               tsuPod[i].title = newTitle;
               tsuPod[i].artist = newArtist;
               tsuPod[i].size = size;
               return 0;
	   }
    	}
    
	//if more than 8 songs
	if (i >= 8)
		return -2;
}

//function to show song list
void showSongList()
{	
	//display the header
	cout << setw(10) << left << "Slot";
	cout << setw(40) << left << "Title";
	cout << setw(30) << left << "Artist";
	cout << setw(10) << left << "Size: MB";
	cout << endl;

	//display songs and slot number
	for(int i = 0; i < NUM_SONGS; i++) {
		cout << setw(10) << left << (i+1);
		cout << setw(40) << left << tsuPod[i].title;
		cout << setw(30) << left << tsuPod[i].artist;
		cout << setw(10) << left << tsuPod[i].size;
		cout << endl;
	}
}

//function to remove song
int removeSong (string title)
{
    //remove song if titles match
    int i = 0;    
    while (i <= NUM_SONGS - 1) { 
          if(tsuPod[i].title == title) {
              tsuPod[i].title = "EMPTY";
              tsuPod[i].artist = "EMPTY";
              tsuPod[i].size = 0;
              return 0;
              }
          else
              i++;
    }
    
    if (i > NUM_SONGS-1)
       return -1;
}

//function to clear memory
void clearMemory()
{
	//clear memory
	for(int i = 0; i < NUM_SONGS; i++) {
		tsuPod[i].title = " ";
		tsuPod[i].artist = " ";
		tsuPod[i].size = 0;
	}
}

//function to shuffle songs
void shuffle ()
{
	//generate seed
	srand(time(0));

	//variables
	TsuPod tempVariable;
	int r = 0;

	//randomly shuffle songs
	 for(int i = 0; i < NUM_SONGS; i++) {
            r = rand() % NUM_SONGS; 
            tempVariable = tsuPod[i];
	    tsuPod[i] = tsuPod[r];
	    tsuPod[r] = tempVariable;
        }
}


