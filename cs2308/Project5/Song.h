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

using namespace std;

class Song
{
	private:
	string artist;
	string title;
	int    size;
	int    position;
	
	public:
	//Mutators
	void setTitle(string t) {title = t;}
	void setArtist(string a) {artist = a;}
	void setSize(int s) {size = s;}
	//Accessors
	string getTitle() const {return title;}
	string getArtist() const {return artist;}
	int getSize() const {return size;}


	//Overload
	//????????????

	//Constructors
	Song();
	Song(string title, string artist, int size, int currentSize, int currentPosition);

	





	





};
#endif
