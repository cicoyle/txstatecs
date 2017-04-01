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

using namespace std;

int main()
{	
	//Tsupod Constructor pass max mem & max songs
	TsuPod tPod(10,1);

	//initialze variables
	int retCode;
	int totalSongs = 0;
	int totalMem = 0;

	//call function to initialize tsupod
	retCode = tPod.initializeTsuPod();
	
	//varify that file opened
	if(retCode == -1) {
		cout << "Error. file did not open.";
		return -1;
	}
	
	//add songs and test tsupod using retCode
	retCode = tPod.addSong("7 Years", "Lukas Graham", 4, 1, totalSongs, totalMem);
//	retCode = tPod.addSong("Caroline", "Amine", 3, 2, totalSongs, totalMem);
	//retCode = tPod.addSong("Little Do You Know", "Alex & Sierra", 2, 3, totalSongs, totalMem);
	//retCode = tPod.addSong("Formation", "Beyonce", 2, 4, totalSongs, totalMem);
	//retCode = tPod.addSong("Closer", "The Chainsmokers", 1, 5, totalSongs, totalMem);
	//retCode = tPod.addSong("Fake Love", "Drake", 4, 6, totalSongs, totalMem);
	//retCode = tPod.addSong("Shape of You", "Ed Sheeran", 1, 7, totalSongs, totalMem);
	//retCode = tPod.addSong("My Name is", "Eminem", 2, 8, totalSongs, totalMem);
	//retCode = tPod.addSong("Work from Home", "Fifth Harmony", 3, 9, totalSongs, totalMem);
	//retCode = tPod.addSong("Never Be Like You", "Flume", 2, 10, totalSongs, totalMem);
	//retCode = tPod.addSong("I Hate You I Love You", "Gnash", 5, 11, totalSongs, totalMem);
	//retCode = tPod.addSong("No Role Modelz", "J. Cole", 2, 12, totalSongs, totalMem);
	//retCode = tPod.addSong("Issues", "Julia Michaels", 1, 13, totalSongs, totalMem);
	//retCode = tPod.addSong("Panda", "Desiigner", 3, 14, totalSongs, totalMem);
	//retCode = tPod.addSong("Black Beatles", "Rae Sremmurd", 5, 15, totalSongs, totalMem);
	//retCode = tPod.addSong("Lost Boy", "Ruth B", 2, 16, totalSongs, totalMem);
	//retCode = tPod.addSong("Side To Side", "Ariana Grande", 2, 17, totalSongs, totalMem);
	//retCode = tPod.addSong("Dont Tell Nobody", "Tink", 1, 18, totalSongs, totalMem);
	//retCode = tPod.addSong("Treat You Better", "Shawn Mendez", 3, 19, totalSongs, totalMem);
	//retCode = tPod.addSong("Climax", "Usher", 1, 20, totalSongs, totalMem);
	//retCode = tPod.addSong("Make Me (Cry)", "Noah Cyrus", 2, 21, totalSongs, totalMem);
	//retCode = tPod.addSong("Play That Song", "Train", 1, 22, totalSongs, totalMem);
	//retCode = tPod.addSong("Paris", "The Chainsmokers", 5, 23, totalSongs, totalMem);
	//retCode = tPod.addSong("Starboy", "The Weeknd", 3, 24, totalSongs, totalMem);
	//retCode = tPod.addSong("Flashlight", "The Front Bottoms", 2, 25, totalSongs, totalMem);

	tPod.showList();
	
	return 0;	
}

