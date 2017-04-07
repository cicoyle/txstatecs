/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include "tsuPod.h"

using namespace std;

int main()
{	
	//Tsupod Constructor pass max mem & max songs
	TsuPod CassiePod(100, 25);

	//initialze variables
	int retCode;

	//call function to initialize tsupod
	retCode = CassiePod.initializeTsuPod();
	
	//varify that file opened
	if(retCode == -1) {
		cout << "Error. file did not open.";
		return -1;
	}
	


	//add songs and test tsupod using retCode
	retCode = CassiePod.addSong("7 Years", "Lukas Graham", 4, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Caroline", "Amine", 3, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Little Do You Know", "Alex & Sierra", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Formation", "Beyonce", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Closer", "The Chainsmokers", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Fake Love", "Drake", 4, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Shape of You", "Ed Sheeran", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("My Name is", "Eminem", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Work from Home", "Fifth Harmony", 3, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Never Be Like You", "Flume", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("I Hate You I Love You", "Gnash", 5, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("No Role Modelz", "J. Cole", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Issues", "Julia Michaels", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Panda", "Desiigner", 3, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Black Beatles", "Rae Sremmurd", 5, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Lost Boy", "Ruth B", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Side To Side", "Ariana Grande", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Dont Tell Nobody", "Tink", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Treat You Better", "Shawn Mendez", 3, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Climax", "Usher", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Make Me (Cry)", "Noah Cyrus", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Play That Song", "Train", 1, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Paris", "The Chainsmokers", 5, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Starboy", "The Weeknd", 3, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Flashlight", "The Front Bottoms", 2, 0);
	cout << "SUCCESS: " << retCode << endl;
	retCode = CassiePod.addSong("Cold Water", "Justin Bieber", 3, 0);
	cout << "UNSUCCESS: " << retCode << endl;


	
	CassiePod.showList();

	CassiePod.removeSong("7 Years", "Lukas Graham", 4);	
	
	CassiePod.clearList();
	cout << "CLEARED: " << endl;		

/*	for(int index = 0; index < 100; index++) {
		tPod.getSong(tPod.getRandomNum());
		return 0;
	}
*/
	//tPod.showList();
	//tPod.shuffle();
	return 0;	
}

