/****************************************************
Name: Cassandra Coyle
Date: 3/12/17
Problem Number:4
Hours spent solving the problem: 8
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>


#include "tsuPod.h"

using namespace std;

int main() 
{
     
    // Following code initializes the tsuPod 
    initTsuPod();

    cout << "INITIALIZED PLAYLIST: " << endl;    
    // Following code lists all songs located in tsuPod memory 
    showSongList();
    cout << endl;

    // adds 8 songs correctly-success
    // Following code tests tsuPod input functionality 
    int retCode = addSong("Blue Ain't Your Color", "Keith Urban", 1);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("Make Me (Cry)", "Noah Cyrus", 2);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("Little Do You Know", "Alex and Sierra", 3);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("Caroline", "Amine", 1);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("Fake Love", "Drake", 5);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("Shape Of You", "Ed Sheeran", 6);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("I Hate You I Love You", "Gnash", 1);
	cout << "SUCCESS: " << retCode << endl;
    retCode = addSong("No Role Modelz", "J. Cole", 1);
	cout << "SUCCESS: " << retCode << endl;

    //unsuccess-lacks memory
    retCode = addSong("Issues", "Julia Michaels", 24);
	cout << "UNSUCCESS-lacks memory: " << retCode << endl;

    //unsuccess-no empty slots
    retCode = addSong("Lost Boy", "Ruth B", 1);
	cout << "UNSUCCESS-no empty slots: " << retCode << endl;
    retCode = addSong("Don't Tell Nobody", "Tink", 1);
	cout << "UNSUCCESS-no empty slots: " << retCode << endl;

    
    cout << "SONGS IN PLAYLIST: " << endl;
    showSongList();
    cout << endl;

    // Following code tests tsuPod song removal functionality         
    retCode = removeSong("Make Me (Cry)");
    cout << "SUCCESSFULLY REMOVED: " << retCode << endl; 

    //retcode when song is not in playlist
    retCode = removeSong("Cookie Monster");
    cout << "UNSUCCESSFULLY REMOVED-song is not in playlist: " << retCode << endl;  
 

    //display playlist when song is removed
    cout << "PLAYLIST SHOWING REMOVED SONG: " << endl;  
    showSongList();
    cout << endl;


    // Following code tests tsuPod song shuffling functionality      
    shuffle();
    cout << endl;

    //display shuffled playlist
    cout << "SHUFFLED PLAYLIST: " << endl;
    showSongList();
    cout << endl;


   //display cleared playlist
   cout << "CLEARED PLAYLIST: " << endl;
   clearMemory();   
   showSongList();
    
    
}
