/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <string>
#include "Song.h"
//Delete this
#include <iostream>

using namespace std;

//Default Constructor
Song::Song()
{
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

//Constructor
Song::Song(string t, string a, int s)
{
	setTitle(t);
	setArtist(a);
	setSize(s);
	std::cout << "new song: " << t << ", by " << a << "memory: " << s << endl;
}

int Song::binarySize() 
{
	return getTitle().size() + getArtist().size() + sizeof(int) + 2;
}


/*
bool Song::operator > (const Song &s1)
{
	bool status;

	if(*title > *s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator < (const Song &s1)
{
	bool status;

	if(*title < *s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator == (const Song &s1)
{
	bool status;

	if(*title == *s1.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool Song::operator != (const Song &sBlank)
{
	bool status;

	if(*title != *sBlank.title)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
*/
