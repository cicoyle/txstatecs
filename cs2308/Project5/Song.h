/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef Song_h
#define Song_h

#include <string>

using namespace std;

class Song
{
	private:
	string artist, title;
	int    size;
	
	public:
	//Constructors
	Song();
	Song(string title, string artist, int size);

	//Mutators
	void setTitle(string t) {title = t;}
	void setArtist(string a) {artist = a;}
	void setSize(int si) {size = si;}

	//Accessors
	string getTitle() {return title;}
	string getArtist() {return artist;}
	int getSize() {return size;}

	int binarySize();

	//Overload
/*	bool operator >(const Song &s);
	bool operator <(const Song &s);
	bool operator ==(const Song &s);
*/	
};
#endif
