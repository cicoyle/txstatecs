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

TsuPod::TsuPod(int mem, int songCount)
{
	cout << "NEW TSUPOD: " << endl;
	
	//assign variables
	memory = mem;
	songs = songCount;
	currentMem = currentSong = 0;
  	songs = songCount;
	
	//allocate memory and display each song length
 	prefixSum = new int[songCount];
  	cout << "addr(offsets): " << prefixSum << endl;
  	for (int song = 0; song < songCount; song++)
    		*(prefixSum + song) = 0;
	
}

//initialize tsupod
int TsuPod::initializeTsuPod()
{
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
Song TsuPod:: getWholeSong(int posi) 
{
	iostuff.open("tsupod_memory.dat", fstream::in | fstream::binary);

	int binarySize = lengthOf(posi);
	int size = 0;
	char titleAndArtist[binarySize];

	iostuff.seekg(getPrefixSum(posi), iostuff.beg);
	iostuff.read(reinterpret_cast<char *>(titleAndArtist), binarySize - 4);
	iostuff.read(reinterpret_cast<char *>(&size), sizeof(int));                                                                                       
	char *artist = titleAndArtist;
	
	while (*(++artist) != '\0');
		artist++;                                                                                                                                       
                                                                                                                                                                        
                //Title, artist variables                                                                                                                               
                string t (titleAndArtist);                                                                                                                                        
                string a (artist);                                                                                                                                      
                                                                                                                                                                        
                //Pass data to object                                                                                                                                   
                Song s (t, a, size);                                                                                                                                    
		
//                cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.getArtist () << "\", " << s.getSize () << ")" << endl;
		iostuff.close();         
                return s;                                                                                                                                                               
                  

}
void TsuPod::updatePrefixSum(int posi, int delta)
{
//	cout << "update position: " << posi << "delta: " << delta << endl;
//	cout << "current value: " << *(prefixSum + posi) << " --- new value: " << *(prefixSum + posi);
//	cout << endl;
	
	*(prefixSum + posi) = *(prefixSum + posi) + delta;
	if(++posi < (currentSong + 1))
		updatePrefixSum(posi, delta);

}

int TsuPod::lengthOf(int posi)
{
	if(posi<=0)
		return *(prefixSum);
	else
		return (getPrefixSum(posi + 1) - getPrefixSum(posi));
}

int TsuPod::getPrefixSum(int position)
{
	if(!position)
		return 0;
	else
		return *(prefixSum + position - 1);
}

void TsuPod::printPrefixSum()
{
/*	cout << "currentSong #: " << currentSong << endl;
	cout << "*(prefixSum + i):"<<endl;

	for(int i = 0; i < songs; i++)
		cout << "(" << i << " :: " << *(prefixSum + i) << ")" << endl;

	cout << "getPrefixSum(i):" <<endl;

	for(int i = 0; i < songs; i++)
		cout << "(" << i << " :: " << getPrefixSum(i) << endl;

	cout<< "lengthof(i):"<<endl;

	for(int i = 0; i < songs; i++)
*///		cout << "(" << i << " :: " << lengthOf(i) << endl;
}

int TsuPod::insertSong (Song s, int position)
{
	//Create char array to allow deep copy of string
  	char title[s.getTitle ().size () + 1];
  	strcpy (title, s.getTitle ().c_str ());

  	char artist[s.getArtist ().size () + 1];
  	strcpy (artist, s.getArtist ().c_str ());

	//Other variables to help with correct location
  	int size = s.getSize();
  	int insertionPoint = getPrefixSum(position);
  	bool lastSong = (position == currentSong - 1);
  	int fileSize = getPrefixSum(currentSong); //File size
  	void *temporaryArray = malloc(fileSize); //Temp variable to store file
  	
//	cout << "lastSong == " << lastSong << endl;
  	
	//Open file in binary
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
	
//	cout << "current song at insertion point: " << currentSong << endl;
  //	cout << "file size copied into mem: " << getPrefixSum(currentSong) << endl;

	//Read in to tmpbuf the file and close file
  	iostuff.read ((char *) temporaryArray, fileSize);
  	iostuff.close ();

	//Show how many bytes were copied
  //	cout << "copied " << fileSize << " bytes from tsupod_mem.dat" << endl;
  //	cout << "writing up to byte " << getPrefixSum (position) << endl;

	//Open file
  	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in | fstream::out);
  	
	//Show where insert point is
//	cout << "INSERT POINT: " << insertionPoint << endl;
//	cout << "binary size: " << s.binarySize() << endl;
//	cout << "w[0:" << insertionPoint << "] \t\t preinsert old file contents." << endl;

	//Write the file up to insertion point
  	iostuff.write ((char *) temporaryArray, insertionPoint);

	//Variable to tell me where I am
  	long pos = iostuff.tellp ();
  //	cout << "w[" << pos;
  	
	//Write to file
	iostuff.write (reinterpret_cast < char *>(title), s.getTitle ().size () + 1);
  	iostuff.write (reinterpret_cast < char *>(artist), s.getArtist ().size () + 1);
	iostuff.write (reinterpret_cast < char *>(&size), sizeof (int));

	//Check position in file
  	pos = iostuff.tellp ();
  //	cout << ":" << pos << "] \t new song\nw[" << pos << ":" << fileSize + s.binarySize ()
//	     << "] \t post insert old file contents." << endl;

	//Write the rest of the file after song was added
    	iostuff.write (reinterpret_cast < char *>(temporaryArray) + insertionPoint, fileSize - insertionPoint);
	
//	cout << "writing end of file" << endl;
//	cout << "PRESHUFFLE DOWN FOR INSERT:" << endl;
//	printPrefixSum();
//	cout << "lengthOf(0): " << lengthOf(0);
	
	//Show me offsets for consumed songs
	if(currentSong >= 1)
  		for (int i = currentSong; i >= position; i--)
		{
//			cout << "moving offsets:\t pos:[" << i << "]v:" << *(prefixSum + i) << endl;
//			cout << "\tto pos:[" << i + 1 << "]v:" << *(prefixSum + i + 1) << endl;
			*(prefixSum + i + 1) = *(prefixSum + i);
		}

//	cout << "PREUPDATE:" << endl;
	
	if(position == 0)
		*(prefixSum) = s.binarySize();
	
	//Update offsets
	updatePrefixSum (position + 1, s.binarySize());
//	cout << "postupdate!!!!:" << endl;
//	printPrefixSum();

  	//Close the file
  	iostuff.close ();
}


int TsuPod::validateAddSong(string t, string a, int si, int currentMem)
{
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


//Add desired song to playlist
int TsuPod::addSong(string t, string a, int si, int position)
{
	//validate that can song be added
	if(validateAddSong(t, a, si, currentMem) < 0)
		return -1;
	
	Song s(t, a, si);
	insertSong(s, position);

	//Add size of added song to mem total
	currentMem += si;

	//If not errors, increment song total
	currentSong++;

	return 0;

}

//Remove desired song to playlist
int TsuPod::removeSong(string t, string a, int si)
{
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

//HITHER

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
int TsuPod::clearList()
{



}

//Sort the song list alphabetically
int TsuPod::sortList()
{
	

}

//Dislay the list to the console
void TsuPod::showList()
{
	Song s;
  	
	//Open file
	iostuff.open ("tsupod_memory.dat", fstream::binary | fstream::in);
  	cout << endl << endl << "Song List: " << endl;

  	for (int i = 0; i < currentSong; i++)
    	{
		//Variables
      		long posi = iostuff.tellg ();
      		int textSize = lengthOf(i);	//Size for text
      		char text[textSize];	//Holds title and artist
      		int size = 0;	//Holds size of song
//
  //    		cout << "textSize == " << textSize;
    //  		cout << "r[" << posi << ":";

		//Read the data to be able to print out
      		iostuff.read (reinterpret_cast < char *>(text), textSize - 4);
      		iostuff.read (reinterpret_cast < char *>(&size), sizeof (int));

      		posi = iostuff.tellg ();
      //		cout << posi << "] :: " << endl;

		//Assign artist
      		char *artist = text;
      		while (*(++artist) != '\0');
      			artist++;

		//Title, artist variables
      		string t (text);
      		string a (artist);

		//Pass data to object
      		Song s (t, a, size);
      		cout << "TsuPod::showList::Song(\"" << s.getTitle () << "\", \"" << s.
		getArtist () << "\", " << s.getSize () << ");" << endl;
    	}
	
	//Display remaining memory to console
	cout << "Total remaining memory: " << getRemainingMem(currentMem) << endl;
	
	//Close file
	iostuff.close ();

	
}

//Display the total memory space left over
int TsuPod::getTotalMem()
{
	return memory;
}

//Shuffle the song list into a different order
int TsuPod::shuffle()
{

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





}

//Get the remaining memory space left over
int TsuPod::getRemainingMem(int currentMem)
{
	return (getTotalMem() - currentMem);
}


