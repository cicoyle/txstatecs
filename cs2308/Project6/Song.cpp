/****************************************************
Name: Cassandra Coyle
Date: 4/18/17
Problem Number: 6
Hours spent solving the problem: 17
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include "Song.h"

using namespace std;

//Default Constructor
Song::Song() {
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

//Constructor
Song::Song(string t, string a, int si) {
	setTitle(t);
	setArtist(a);
	setSize(si);
}


//overload
bool Song::operator > (const Song & otherSong) {
	if(title > otherSong.title)
		return title > otherSong.title;
	else if(artist > otherSong.artist)
		return artist > otherSong.artist;
	else if(size > otherSong.size)
		return size > otherSong.size;
	else
		return false;
}

bool Song::operator < (const Song & otherSong) {
	if(title < otherSong.title)
		return title < otherSong.title;
	else if(artist < otherSong.artist)
		return artist < otherSong.artist;
	else if(size < otherSong.size)
		return size < otherSong.size;
	else
		return false;
}

bool Song::operator == (const Song & otherSong) {
	if((title == otherSong.title) && (artist == otherSong.artist) && (size == otherSong.size))
		return false;
	else 
		return true;
}

bool Song::operator != (const Song & otherSong) {
	if((title != otherSong.title) && (artist != otherSong.artist) && (size != otherSong.size))
		return false;
	else 
		return true;
}
