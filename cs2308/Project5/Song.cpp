/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/
#include <string.h>
#include "Song.h"
#include <stdio.h>
//Delete this
#include <iostream>

using namespace std;

//Default Constructor
Song::Song()
{
	size = 0;
	position = 0;
	setTitle("EMPTY");
	setArtist("EMPTY");
	setSize(0);
}

//Constructor
Song::Song(string t, string a, int s, int currentSize, int currentPosition)
{
	size = currentSize;
	position = currentPosition;
	setTitle(t);
	setArtist(a);
	setSize(s);
	std::cout << "new song: " << t << ", by " << a << endl;
}




/*
void Song::setArtist(char *songArtist)		// Sets artist private member within Song object
{
	strcpy(artist, songArtist);
}

void Song::setTitle(char *songTitle)		// Sets title private member within Song object
{
	strcpy(title, songTitle);
}

void Song::setSize(int songSize)		// Sets size private member within Song object
{
	size = songSize;
}

void Song::setPosition(int songNum)		// Sets position private member within Song object
{
	position = songNum;
}

const char* Song::getArtist() const		// Retrieves artist from Song
{
	return artist;
}

const char* Song::getTitle() const		// Retrieves title from Song
{
	return title;
}

int Song::getSize() const			// Retrieves size from Song
{
	return size;
}
*/
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
}*/
