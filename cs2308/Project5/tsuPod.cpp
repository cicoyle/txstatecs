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
	
	//assign variables
	memory = mem;
	songs = songCount;
	currentMem = currentSong = 0;

	//show total memory
	cout << "total memory: " << mem << endl;
	
	//allocate memory
 	prefixSum = new int[songCount];
  	
	for (int song = 0; song < songCount; song++)
    		*(prefixSum + song) = 0;
	
}

//initialize tsupod
int TsuPod::initializeTsuPod() {
	//declare song object
	Song s;

	//open file in binary
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

//get the song
Song TsuPod:: getWholeSong(int posi) {
	//open file
	iostuff.open("tsupod_memory.dat", fstream::in | fstream::binary);

	//variables
	int size = 0;
	int binarySize = lengthOf(posi);
	
	//array to hold title and artist
	char titleAndArtist[binarySize];

	//seek and read file
	iostuff.seekg(getPrefixSum(posi), iostuff.beg);
	iostuff.read(reinterpret_cast<char *>(titleAndArtist), binarySize - 4);
	iostuff.read(reinterpret_cast<char *>(&size), sizeof(int));   

	//assign artist                                                                                    
	char *artist = titleAndArtist;
	
	//increment artist while its not null
	while (*(++artist) != '\0');
		artist++;                                                                                                                                       
        //Title, artist variables                                                                                          
	string t (titleAndArtist);                                                                                                                             string a (artist);       
        
	//pass objects title, artist, size
	Song s(t, a, size);	
	
	//close file
	iostuff.close();         
        
	//return object
	return s;                                                                                                                                                               
}

//update the prefix sum function
void TsuPod::updatePrefixSum(int posi, int delta) {
	//calculate the prefix sum + position
	*(prefixSum + posi) = *(prefixSum + posi) + delta;

	//if the incremented position is smaller than the currentsong +1
	if(++posi < (currentSong + 1))
		updatePrefixSum(posi, delta);

}

//lenght of function
int TsuPod::lengthOf(int posi) {
	//if the position is smaller than or equal to 0
	if(posi<=0)
		return *(prefixSum);
	else
		return (getPrefixSum(posi + 1) - getPrefixSum(posi));
}

//get the prefix sum function
int TsuPod::getPrefixSum(int position) {
	//if not position
	if(!position)
		return 0;
	else
		return *(prefixSum + position - 1);
}

//insert the actual song function
int TsuPod::insertSong (Song s, int position) {
	//arrays
  	char title[s.getTitle ().size () + 1];
  	char artist[s.getArtist ().size () + 1];
  	
	//string copy
	strcpy (title, s.getTitle ().c_str ());
  	strcpy (artist, s.getArtist ().c_str ());

	//variables
  	int size = s.getSize();
  	int addInSpot = getPrefixSum(position);
  	bool lastSong = (position == currentSong - 1);
  	int fileSize = getPrefixSum(currentSong); 
  	void *temporaryArray = malloc(fileSize); 
  	
	//Open file
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
	
	//Read & close file
  	iostuff.read ((char *) temporaryArray, fileSize);
  	iostuff.close ();

	//Open file
  	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
  	
	//Write up until the add in spot
  	iostuff.write ((char *) temporaryArray, addInSpot);

	//Variable to tell me where I am
  	long pos = iostuff.tellp ();
  	
	//Write to file
	iostuff.write (reinterpret_cast < char *>(title), s.getTitle ().size () + 1);
  	iostuff.write (reinterpret_cast < char *>(artist), s.getArtist ().size () + 1);
	iostuff.write (reinterpret_cast < char *>(&size), sizeof (int));

	//Check position
  	pos = iostuff.tellp ();
	
	//Write the rest of the file after song was added
    	iostuff.write (reinterpret_cast < char *>(temporaryArray) + addInSpot, fileSize - addInSpot);
	
	//if current song is bigger than or equal to 1
	if(currentSong >= 1)
  		for (int i = currentSong; i >= position; i--)
			*(prefixSum + i + 1) = *(prefixSum + i);

	//if the position is 0
	if(position == 0)
		*(prefixSum) = s.binarySize();
	
	//Update preix sum
	updatePrefixSum (position + 1, s.binarySize());

  	//Close the file
  	iostuff.close ();
}

//validate the song being added function
int TsuPod::validateAddSong(string t, string a, int si, int currentMem) {
	//Check that size is > 0
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
	//validate that can song be added
	if(validateAddSong(t, a, si, currentMem) < 0)
		return -1;

	//song object
	Song s(t, a, si);
	insertSong(s, position);

	//calculate current memory
	currentMem = currentMem + si;

	//increment currentsong
	currentSong++;

	return 0;

}

//Remove song function
int TsuPod::removeSong(string t, string a, int si) {
	//TsuPod Temp(t, a, si);

//	Song s(t, a, si);

//	s.getSong();	

/*
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

//Clear the song list
int TsuPod::clearList() {
	//clear list
	iostuff.close ();
	iostuff.open("tsupod_memory.dat", fstream::out | fstream::trunc);
	iostuff.clear();
}

//Sort the song list alphabetically
int TsuPod::sortList() {
	

}

//show the playlist function
void TsuPod::showList() {
	//declare song object
	Song s;
  	
	//Open file
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in);
  	cout << endl << endl << "Song List: " << endl;

	//for loop to run through songs
  	for (int i = 0; i < currentSong; i++)
    	{
		//Variables
      		long posi = iostuff.tellg ();
      		int tempArraySize = lengthOf(i);
		
		//temp array to hold title and artist	
      		char tempArray[tempArraySize];	
      		int size = 0;

		//Read the file
      		iostuff.read (reinterpret_cast < char *>(tempArray), tempArraySize - 4);
      		iostuff.read (reinterpret_cast < char *>(&size), sizeof (int));

		//position variable
      		posi = iostuff.tellg ();

		//Assign artist
      		char *artist = tempArray;
      		while (*(++artist) != '\0');
      			artist++;

		//Title/Artist variables
      		string t (tempArray);
      		string a (artist);

		//Pass data to object
      		Song s (t, a, size);
      		cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.
		getArtist () << "\", " << s.getSize () << ");" << endl;
    	}
	
	//show remaining memory
	cout << "Total remaining memory: " << getRemainingMem(currentMem) << endl;
	
	//Close file
	iostuff.close ();

	
}

//get total memory function
int TsuPod::getTotalMem() {
	return memory;
}

//Shuffle songs function
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

//Get the remaining memory function
int TsuPod::getRemainingMem(int currentMem) {
	return (getTotalMem() - currentMem);
}


