/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef Song_h
#define Song_h
#include <string>
#include <fstream>

using namespace std;

class Song
{
	private:
		char artist[256];
		char title[256];
		int size;
		int pos;
	public:
		Song();
		Song(char *currentTitle, char *currentArtist, int currentSize, int currentPosition);
		void setTitle(char *songT);
		void setArtist(char *songA);
		void setSize(int songSi);
		void setPosition(int songNumber);
		const char* getArtist() const;
		const char* getTitle() const;
		int getSize() const;
		bool operator >(const Song &s);
		bool operator <(const Song &s);
		bool operator ==(const Song &s);
		bool operator !=(const Song &sBlank);
};

#endif 
