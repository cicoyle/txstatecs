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
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

fstream iostuff;

//constructor
TsuPod::TsuPod(int mem, int songCount) {
	cout << "NEW TSUPOD: " << endl;
	
	//variables
	memory = mem;
	songs = songCount;
	
	//allocate memory
 	prefixSum = new int[songCount];
  	
	//for loop to go through songs
	for (int song = 0; song < songCount; song++)
    		*(prefixSum + song) = 0;
	
}

//initialize tsupod
int TsuPod::initializeTsuPod() {
	//declare song object
	Song s;

	//open file
	iostuff.open("tsupod_memory.dat", ios::out | ios::in | ios::app | ios::binary);
	
	//validate file
	if(!iostuff) {
		cout << "Error. File did not open." << endl;
		return -1;
	}

	//close file
	iostuff.close();

	return 0;
}

//update prefixSum function
void TsuPod::updatePrefixSum(int posi, int delta) {
	//calculate prefixSum and position
	*(prefixSum + posi) = *(prefixSum + posi) + delta;
	
	//if the incremented position is smaller than the current song +1
	if(++posi < (currentSong + 1))
		updatePrefixSum(posi, delta); 	//call update PrefixSum function

}

//get the length of the songs function
int TsuPod::lengthOf(int posi) {
	//if the position is smaller than or equal to 0 return the prefixSum
	if(posi<=0)
		return *(prefixSum);
	//else return the difference
	else
		return (getPrefixSum(posi + 1) - getPrefixSum(posi));
}

//get the prefixSum function
int TsuPod::getPrefixSum(int position) {
	//if it is not the position
	if(!position)
		return 0;
	//else return the prefixSum plus the position minus 1
	else
		return *(prefixSum + position - 1);
}

//insert the song into the file function
int TsuPod::insertSong (Song s, int position) {
	//arrays
  	char title[s.getTitle ().size () + 1];
  	char artist[s.getArtist ().size () + 1];
  	
	//string copy
	strcpy (artist, s.getArtist ().c_str ());
  	strcpy (title, s.getTitle ().c_str ());
	
	//get the file size
  	int fileSize = getPrefixSum(currentSong);

	//variables
  	bool lastSong = (position == currentSong - 1);
  	int placeToAdd = getPrefixSum(position);
  	int size = s.getSize();
	
	//store file
  	void *temporaryArray = malloc(fileSize); 
  	
	cout << "lastSong == " << lastSong << endl;
  	
	//Open file
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
	
	//Read & close the file
  	iostuff.read ((char *) temporaryArray, fileSize);
  	iostuff.close ();

	//Re-open file
  	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
  	
	//write the beginning of the file up until the place to add the song
  	iostuff.write ((char *) temporaryArray, placeToAdd);

	//Variable to tell me where I am
  	long pos = iostuff.tellp ();
  	
	//Write to file plus 1 for null
	iostuff.write (reinterpret_cast < char *>(title), s.getTitle ().size () + 1);
  	iostuff.write (reinterpret_cast < char *>(artist), s.getArtist ().size () + 1);
	iostuff.write (reinterpret_cast < char *>(&size), sizeof (int));

	//find position
  	pos = iostuff.tellp ();

	//Write the rest of the file
    	iostuff.write (reinterpret_cast < char *>(temporaryArray) + placeToAdd, fileSize - placeToAdd);
	
	cout << "writing end of file" << endl;
	cout << "PRESHUFFLE DOWN FOR INSERT:" << endl;
	cout << "lengthOf(0): " << lengthOf(0);
	
	//show prefixSum
	if(currentSong >= 1) 
  		for (int i = currentSong; i >= position; i--)
			*(prefixSum + i + 1) = *(prefixSum + i);

	//if position is 0 prefix sum is size
	if(position == 0)
		*(prefixSum) = s.binarySize();
	
	//Update prefixSum
	updatePrefixSum (position + 1, s.binarySize());

  	//Close the file
  	iostuff.close ();
}

//validate the song being added
int TsuPod::validateAddSong(string t, string a, int si, int currentMem) {
	//Check that size is > 0.
	if(si < 0 && si > ((getRemainingMem(currentMem)))) {
		cout << "Error. Song not added. Size must be greater than 0." << endl;
		return -2;
	}

	//Error-too many songs
	if(currentSong == songs) {
		cout << "Error. Song not added. Lacks space." << endl;
		return -2;
	}
	
	//Error-blank entry
	if(t == " " || a == " ") {
		cout << "Error. Song not added. Title/artist cannot be blank." << endl;
		return -2;
	}

	return 0;
}


//Add song function
int TsuPod::addSong(string t, string a, int si, int position) {
	//declare song object
	Song s(t, a, si);
	
	//if song is not valid
	if(0 > validateAddSong(t, a, si, currentMem))
		return -1;
	
	//call insert song function
	insertSong(s, position);

	//calculate memory total
	currentMem = currentMem + si;	

	//increment curretn songs
	currentSong++;

	return 0;

}

//Remove song function
int TsuPod::removeSong(int position) {
	//TsuPod Temp(t, a, si);
	
/*
	Song s;

	//Open the file in binary
	iostuff.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);

	//Create char arry to allow deep copy of string
	char title[s.getTitle().size() + 1];
	strcpy(title, s.getTitle().c_str());

	char artist[s.getArtist().size() + 1];
	strcpy(artist, s.getArtist().c_str());
	int size = s.getSize();
	
	
	//Get file size and make temp variable
	int fileSize = getPrefixSum(currentSong - 2);
	void * temporaryFile = malloc(fileSize);

	//Copy text over up to song position to be removed
	iostuff.read((char *)temporaryFile, fileSize);
	iostuff.close();

	//Show how many bytes were copied
	cout << "copied " << fileSize << " bytes from tsupod_memory.dat" << endl;
	
//	cout << "In remove song, I am here initially: " << removalPoint << endl;

	iostuff.open("tsupod_memory.dat", fstream::binary | fstream::out | fstream::in);
	
		
	//Write up to position that is going to be removed
  	iostuff.write ((char *) temporaryFile, position);
	
	//get position in file
	long posi = iostuff.tellp();

//	iostuff.write((char *)getPrefixSum(position+1), fileSize);
	//increment temp file pointer the size of song were removing then write again.

	cout << "binary size: " << s.binarySize() << endl;


	//Helper variable to know where I am
//	long pos = iostuff.tellp();
//	cout << "w[" << pos << endl;




//while position is not what is passed in

//	myio.seekp((fileSize - s.blobSize - removalPoint), ios::beg);

	//Write file after song that I want removed
//	iostuff.write(reinterpret_cast<char*>(temporaryFile - removalPoint), (fileSize - removalPoint));
	
	cout << "Writing rest of file" << endl;
	
		
	return 0;
*/
}

//Clear songs function
int TsuPod::clearList() {



}

//Sort songs function
int TsuPod::sortList() {
	

}

//show playlist
void TsuPod::showList() {
	//declare song object
	Song s;
  	
  	cout << endl << endl << "Song List: " << endl;
	
	//Open file
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in);

	//for loop to go through songs
  	for (int i = 0; i < currentSong; i++)
    	{
      		//array
      		int textSize = lengthOf(i);	
		char tempArray[textSize];	
      		//variables
		int size = 0;
		//position variable	
      		long posi = iostuff.tellg ();

  //    		cout << "textSize == " << textSize;
    //  		cout << "r[" << posi << ":";

		//Read file
     		iostuff.read (reinterpret_cast < char *>(tempArray), textSize - 4);
      		iostuff.read (reinterpret_cast < char *>(&size), sizeof (int));

		//find position
      		posi = iostuff.tellg ();
      		cout << posi << "] :: " << endl;

		//Assign artist
      		char *artist = tempArray;
      		while (*(++artist) != '\0');
      			artist++;

		//Title/Artist variables
      		string t (tempArray);
      		string a (artist);

		//declare song object passing in info
      		Song s (t, a, size);
      		cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.
		getArtist () << "\", " << s.getSize () << ");" << endl;
    	}
	
	//show memory
	cout << "Total remaining memory: " << getRemainingMem(currentMem) << endl;
	
	//Close file
	iostuff.close ();
	
}

//Total memory function
int TsuPod::getTotalMem() {
	return memory;
}

//Shuffle function
int TsuPod::shuffle() {
/*
//shuffle position write it in that order
	//generate seed
	srand(time(0));

	//variables
	int temporaryArray[25];
	int r = 0;
	
	//assign int array 0-24
	cout << "tempArray values: "; 
	for(int i = 0; i <= 24; i++) {
		temporaryArray[i] = i; 
		cout << temporaryArray[i] << " ";
	}
	cout << endl;
	cout << "Shuffled array: ";
	//randomly shuffle array contents
	 for(int i = currentSong-1; i > 0; i--) {
            r = rand() % (i + 1); 
            int tempVariable = temporaryArray[i];
	    temporaryArray[i] = temporaryArray[r];
	    temporaryArray[r] = tempVariable;
	    cout << temporaryArray[i] << " ";
        }
	cout << endl;
	//assign array contents to song positions
*/

}

//Remaining memory function
int TsuPod::getRemainingMem(int currentMem) {
	return (getTotalMem() - currentMem);
}


