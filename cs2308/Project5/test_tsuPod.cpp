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
	TsuPod tPod(100,25);

	tPod.addSong(Song("7 Years", "Lukas Graham", 4));
	tPod.addSong(Song("Caroline", "Amine", 3));
	tPod.addSong(Song("Little Do You Know", "Alex & Sierra", 2));
	tPod.addSong(Song("Formation", "Beyonce", 2));
	tPod.addSong(Song("Closer", "The Chainsmokers", 1));
	tPod.addSong(Song("Fake Love", "Drake", 4));
	tPod.addSong(Song("Shape of You", "Ed Sheeran", 1));
	tPod.addSong(Song("My Name is", "Eminem", 2));
	tPod.addSong(Song("Work from Home", "Fifth Harmony", 3));
	tPod.addSong(Song("Never Be Like You", "Flume", 2));
	tPod.addSong(Song("I Hate You I Love You", "Gnash", 5));
	tPod.addSong(Song("No Role Modelz", "J. Cole", 2));
	tPod.addSong(Song("Issues", "Julia Michaels", 1));
	tPod.addSong(Song("Panda", "Desiigner", 3));
	tPod.addSong(Song("Black Beatles", "Rae Sremmurd", 5));
	tPod.addSong(Song("Lost Boy", "Ruth B", 2));
	tPod.addSong(Song("Side To Side", "Ariana Grande", 2));
	tPod.addSong(Song("Dont Tell Nobody", "Tink", 1));
	tPod.addSong(Song("Treat You Better", "Shawn Mendez", 3));
	tPod.addSong(Song("Climax", "Usher", 1));
	tPod.addSong(Song("Make Me (Cry)", "Noah Cyrus", 2));
	tPod.addSong(Song("Play That Song", "Train", 1));
	tPod.addSong(Song("Paris", "The Chainsmokers", 5));
	tPod.addSong(Song("Starboy", "The Weeknd", 3));
	tPod.addSong(Song("Flashlight", "The Front Bottoms", 2));

	tPod.showList();
	
	return 0;	
}

