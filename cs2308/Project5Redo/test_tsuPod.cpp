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
	TsuPod CassiePod(10, 1);
	
	//variables
	int retCode;
	int memTotal = 0;
	int songTotal = 0;

	retCode = CassiePod.getMemTotal();

	cout << "Total memory: " << retCode << endl;
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
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Caroline", "Amine", 3, 2, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Little Do You Know", "Alex & Sierra", 2, 3, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Formation", "Beyonce", 2, 4, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Closer", "The Chainsmokers", 1, 5, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Fake Love", "Drake", 4, 6, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Shape of You", "Ed Sheeran", 1, 7, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("My Name is", "Eminem", 2, 8, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Work from Home", "Fifth Harmony", 3, 9, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Never Be Like You", "Flume", 2, 10, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("I Hate You I Love You", "Gnash", 5, 11, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("No Role Modelz", "J. Cole", 2, 12, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Issues", "Julia Michaels", 1, 13, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Panda", "Desiigner", 3, 14, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Black Beatles", "Rae Sremmurd", 5, 15, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Lost Boy", "Ruth B", 2, 16, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Side To Side", "Ariana Grande", 2, 17, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Dont Tell Nobody", "Tink", 1, 18, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Treat You Better", "Shawn Mendez", 3, 19, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Climax", "Usher", 1, 20, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Make Me (Cry)", "Noah Cyrus", 2, 21, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Play That Song", "Train", 1, 22, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Paris", "The Chainsmokers", 5, 23, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Starboy", "The Weeknd", 3, 24, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Flashlight", "The Front Bottoms", 2, 25, memTotal, songTotal);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Cold Water", "Justin Bieber", 3, 26, memTotal, songTotal);
	cout << "UNSUCCESS: " << retCode << endl;
	
	cout << "Songs added: " << endl;
	//show song list
	CassiePod.showList();
	
	//show remaining memory
	cout << "Remaining memory: ";
//	cout << CassiePod.getRemainingMemory(memTotal) << endl;
	
	//sort list
//	CassiePod.sortList(songTotal);

	cout << "Sorted Song List: " << endl;
	//show song list
//	CassiePod.showList();

	//show remaining memory
//	cout << "Remaining memory: ";
//	cout << CassiePod.getRemainingMemory(memTotal) << endl;

	//remove song
//	retCode = CassiePod.removeSong("No Role Modelz", "J. Cole", 2, 12, memTotal, songTotal);
		

	//show remaining memory after removing song
//	cout << "Remaining memory: ";
//	cout << CassiePod.getRemainingMemory(memTotal);
//	cout << endl << endl;

	//show song list with removed song
	cout << "List with song removed: " << endl;
//	CassiePod.showList();

	//clear song list
//	CassiePod.clearList();	

	//show cleared song list
	cout << "Cleared list: " << endl;
	CassiePod.showList();

	CassiePod.closeFile();	

	return 0;
}
