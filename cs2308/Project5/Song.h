/****************************************************
Name: Cassandra Coyle
Date: 3/24/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#ifndef Song_h
#define Song_h

using namespace std;

#include <string>

class Song
{
    private:
    string artist;
    string title;
    int    size;
    
    public:
    //Accessors
    string getSongTitle() const {return title;}
    string getSongArtist() const {return artist;}
    int    getSongSize() const {return size;}

    //Mutators
    void   setSongTitle(string t) {title = t;}
    void   setSongArtist(string a) {artist = a;}
    void   setSongSize(int s) {size = s;}
    
    //Operator Overload
    //bool operator<(const Song &rhs);
    //bool operator>(const Song &rhs);
    //bool operator==(const Song &rhs);

    //Constructors
    Song();
    Song(string title, string artist, int size);

};


#endif

