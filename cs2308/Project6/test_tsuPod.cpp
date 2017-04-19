/****************************************************
Name: Cassandra Coyle
Date: 4/15/17
Problem Number: 6
Hours spent solving the problem: 10
Instructor: Komogortsev, TSU
*****************************************************/

#include <fstream>
#include<iostream>
#include "tsuPod.h"

using namespace std;


int main() {
	//initialize CassiePod
	TsuPod CassiePod(256);
	
	//retcode variable	
	int retCode;
	
	//song 0 = successful
	Song CassieSong0("Blue Aint't Your Color", "Keith Urban", 1);
	retCode = CassiePod.addSong(CassieSong0);
	cout << "retCode = " << retCode << endl;

	//song 1 = successful
	Song CassieSong1("Shape of You", "Ed Sheeran", 2);
	retCode = CassiePod.addSong(CassieSong1);
	cout << "retCode = " << retCode << endl;

	//song 2 = successful
	Song CassieSong2("Issues", "Julia Michaels", 3); 
	retCode = CassiePod.addSong(CassieSong2);
	cout << "retCode = " << retCode << endl;

	//song 3 = successful
	Song CassieSong3("Paris", "The Chainsmokers", 4);
	retCode = CassiePod.addSong(CassieSong3);
	cout << "add retCode = " << retCode << endl;

	//song 4 = unsuccessful due to blank title and artist
	Song CassieSong4(" ", " ", 5); 
	retCode = CassiePod.addSong(CassieSong4);
	cout << "add retCode = " << retCode << endl;

	//song 5 = successful
	Song CassieSong5("Cold", "Maroon 5", 6);
	retCode = CassiePod.addSong(CassieSong5);
	cout << "add retCode = " << retCode << endl;

	//song 6 = successful
	Song CassieSong6("Green Light", "Lorde", 7);
	retCode = CassiePod.addSong(CassieSong6);
	cout << "add retCode = " << retCode << endl;

	//display list
	cout << endl;
	cout << "Songs added " << endl;
	CassiePod.showList();

	//remove song 2
	retCode = CassiePod.removeSong(CassieSong2); 
	cout << endl <<  "remove retCode = " << retCode << endl;

	//remove song 3
	retCode = CassiePod.removeSong(CassieSong3); 
	cout << "remove retCode = " << retCode << endl;

	//display list
	cout << endl << "List with songs removed" << endl;
	CassiePod.showList(); 

	//display sorted song list
	cout << endl;
        cout << "Sorted Song List" << endl;
	
	//call sort list function
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	CassiePod.sortList(); 
	
	//display sort list
	CassiePod.showList(); 

	//show shuffled list
	cout << endl;
	cout << "List Shuffled" << endl;
	
	//call shuffle function
	CassiePod.shuffle(); 
	
	//display shuffled list
	CassiePod.showList(); 

	cout << endl << "Memory with used" << endl;
	//show total & remaining memory
	cout << CassiePod.getRemainingMem() << "MB out of " << CassiePod.getMemTotal() << "MB." << endl;

	//call clear list
	CassiePod.clearList(); 
	
	//display cleared list
	CassiePod.showList();

	cout << endl << "Memory with cleared list" << endl;
	//show total & remaining memory after song list cleared
	cout << CassiePod.getRemainingMem() << "MB out of " << CassiePod.getMemTotal() << "MB." << endl;

	//call the deconstructor
	CassiePod.~TsuPod(); 

	return 0;
}
