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

int main() {

	//constructor
	TsuPod CassiePod(100, 25);
	
	//variables
	int retCode;
	int memTotal = 0;
	int songTotal = 0;

	cout << "Total memory: " << memTotal << endl << endl;

	//initialize
	retCode = CassiePod.initializeTsuPod();
		if(retCode == -1) {
			cout << "Error. File did not open";
			return -1;
	}

	cout << "Initialized Song List: " << endl;
	//show song list
	retCode = CassiePod.showList();

	//add songs and test tsupod using retCode
	retCode = CassiePod.addSong("7 Years", "Lukas Graham", 4, 1, memTotal, songTotal);
	retCode = CassiePod.addSong("Caroline", "Amine", 3, 2, memTotal, songTotal);
	retCode = CassiePod.addSong("Little Do You Know", "Alex & Sierra", 2, 3, memTotal, songTotal);
	retCode = CassiePod.addSong("Formation", "Beyonce", 2, 4, memTotal, songTotal);
	retCode = CassiePod.addSong("Closer", "The Chainsmokers", 1, 5, memTotal, songTotal);
	retCode = CassiePod.addSong("Fake Love", "Drake", 4, 6, memTotal, songTotal);
	retCode = CassiePod.addSong("Shape of You", "Ed Sheeran", 1, 7, memTotal, songTotal);
	retCode = CassiePod.addSong("My Name is", "Eminem", 2, 8, memTotal, songTotal);
	retCode = CassiePod.addSong("Work from Home", "Fifth Harmony", 3, 9, memTotal, songTotal);
	retCode = CassiePod.addSong("Never Be Like You", "Flume", 2, 10, memTotal, songTotal);
	retCode = CassiePod.addSong("I Hate You I Love You", "Gnash", 5, 11, memTotal, songTotal);
	retCode = CassiePod.addSong("No Role Modelz", "J. Cole", 2, 12, memTotal, songTotal);
	retCode = CassiePod.addSong("Issues", "Julia Michaels", 1, 13, memTotal, songTotal);
	retCode = CassiePod.addSong("Panda", "Desiigner", 3, 14, memTotal, songTotal);
	retCode = CassiePod.addSong("Black Beatles", "Rae Sremmurd", 5, 15, memTotal, songTotal);
	retCode = CassiePod.addSong("Lost Boy", "Ruth B", 2, 16, memTotal, songTotal);
	retCode = CassiePod.addSong("Side To Side", "Ariana Grande", 2, 17, memTotal, songTotal);
	retCode = CassiePod.addSong("Dont Tell Nobody", "Tink", 1, 18, memTotal, songTotal);
	retCode = CassiePod.addSong("Treat You Better", "Shawn Mendez", 3, 19, memTotal, songTotal);
	retCode = CassiePod.addSong("Climax", "Usher", 1, 20, memTotal, songTotal);
	retCode = CassiePod.addSong("Make Me (Cry)", "Noah Cyrus", 2, 21, memTotal, songTotal);
	retCode = CassiePod.addSong("Play That Song", "Train", 1, 22, memTotal, songTotal);
	retCode = CassiePod.addSong("Paris", "The Chainsmokers", 5, 23, memTotal, songTotal);
	retCode = CassiePod.addSong("Starboy", "The Weeknd", 3, 24, memTotal, songTotal);
	retCode = CassiePod.addSong("Flashlight", "The Front Bottoms", 2, 25, memTotal, songTotal);

	cout << "RetCode: " << retCode;
	cout << endl << endl;

	cout << "Songs added: " << endl;
	//show song list
	CassiePod.showList();

	//sort list
	CassiePod.sortList(songTotal);

	cout << "Sorted Song List: " << endl;
	//show song list
	CassiePod.showList();

	//show remaining memory
	cout << "Remaining memory: ";
	cout << CassiePod.getRemainingMemory(memTotal) << endl;

	//remove song
	retCode = CassiePod.removeSong("No Role Modelz", "J. Cole", 2, 12, memTotal, songTotal);

	//show remaining memory after removing song
	cout << "Remaining memory: ";
	cout << CassiePod.getRemainingMemory(memTotal);
	cout << endl << endl;

	//show song list with removed song
	cout << "List with song removed: " << endl;
	CassiePod.showList();

	//clear song list
	CassiePod.clearList();	

	//show cleared song list
	cout << "Cleared list: " << endl;
	CassiePod.showList();

	CassiePod.closeFile();	

	return 0;
}
