/****************************************************
Name: Cassandra Coyle
Date: 3/24/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
//REMOVE THE ABOVE AFTER ITS ALL WORKING
#include <string>
#include "Song.h"


// Song a, b;
// if ( a < b )
// ...
// ????????????
/*

a.operator<(b)


*/
using namespace std;

/*
bool Song::operator<(const Song &rhs)
{
    if (getSongTitle() != rhs.getSongTitle())
    {
        return getSongTitle() < rhs.getSongTitle();
    }

    if (getSongArtist() !=rhs.getSongArtist())
    {
       return getSongArtist() < rhs.getSongArtist();
    }
    
    return getSongSize() < rhs.getSongSize();
}

bool Song::operator>(const Song &rhs)
{
    if (getSongTitle() != rhs.getSongTitle())
    {
        return getSongTitle() > rhs.getSongTitle();
    }
    
    if (getSongArtist() !=rhs.getSongArtist())
    {
        return getSongArtist() > rhs.getSongArtist();
    }
    
    return getSongSize() > rhs.getSongSize();
}

bool Song::operator==(const Song &rhs)
{
    if (getSongTitle() != rhs.getSongTitle())
        return false;
    if (getSongArtist() != rhs.getSongArtist())
        return false;
    if (getSongSize() != rhs.getSongSize())
        return false;
    else
        return true;
}

*/
//Constructors
Song::Song()
{
    setSongTitle("EMPTY");
    setSongArtist("EMPTY");
    setSongSize(0);
}

Song::Song(string t, string a, int s)
{
    setSongTitle(t);
    setSongArtist(a);
    setSongSize(s);
std::cout << "New song! " << t << ", by " << a << endl;
}




