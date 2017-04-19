/****************************************************
Name: Cassandra Coyle
Date: 4/18/17
Problem Number: 6
Hours spent solving the problem: 17
Instructor: Komogortsev, TSU
*****************************************************/

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
	//deconsttuctor
	~Song() {};

	//Mutators
	void setTitle(string t) {title = t;}
	void setArtist(string a) {artist = a;}
	void setSize(int si) {size = si;}

	//Accessors
	string getTitle() {return title;}
	string getArtist() {return artist;}
	int getSize() {return size;}

	//Overload
	bool operator >(const Song &);
	bool operator <(const Song &);
	bool operator ==(const Song &);
	bool operator !=(const Song &);
	
};
