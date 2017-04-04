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
	TsuPod tPod(100, 25);

	//initialze variables
	int retCode;

	//call function to initialize tsupod
	retCode = tPod.initializeTsuPod();
	
	//varify that file opened
	if(retCode == -1) {
		cout << "Error. file did not open.";
		return -1;
	}
	
	//add songs and test tsupod using retCode
	retCode = tPod.addSong("7 Years", "Lukas Graham", 4, 0);
	retCode = tPod.addSong("Caroline", "Amine", 3, 0);
	retCode = tPod.addSong("Little Do You Know", "Alex & Sierra", 2, 0);
	retCode = tPod.addSong("Formation", "Beyonce", 2, 0);
	retCode = tPod.addSong("Closer", "The Chainsmokers", 1, 0);
	retCode = tPod.addSong("Fake Love", "Drake", 4, 0);
	retCode = tPod.addSong("Shape of You", "Ed Sheeran", 1, 0);
	retCode = tPod.addSong("My Name is", "Eminem", 2, 0);
	retCode = tPod.addSong("Work from Home", "Fifth Harmony", 3, 0);
	retCode = tPod.addSong("Never Be Like You", "Flume", 2, 0);
	retCode = tPod.addSong("I Hate You I Love You", "Gnash", 5, 0);
	retCode = tPod.addSong("No Role Modelz", "J. Cole", 2, 0);
	retCode = tPod.addSong("Issues", "Julia Michaels", 1, 0);
	retCode = tPod.addSong("Panda", "Desiigner", 3, 0);
	retCode = tPod.addSong("Black Beatles", "Rae Sremmurd", 5, 0);
	retCode = tPod.addSong("Lost Boy", "Ruth B", 2, 0);
	retCode = tPod.addSong("Side To Side", "Ariana Grande", 2, 0);
	retCode = tPod.addSong("Dont Tell Nobody", "Tink", 1, 0);
	retCode = tPod.addSong("Treat You Better", "Shawn Mendez", 3, 0);
	retCode = tPod.addSong("Climax", "Usher", 1, 0);
	retCode = tPod.addSong("Make Me (Cry)", "Noah Cyrus", 2, 0);
	retCode = tPod.addSong("Play That Song", "Train", 1, 0);
	retCode = tPod.addSong("Paris", "The Chainsmokers", 5, 0);
	retCode = tPod.addSong("Starboy", "The Weeknd", 3, 0);
	retCode = tPod.addSong("Flashlight", "The Front Bottoms", 2, 0);

	tPod.showList();
	
	return 0;	
}

