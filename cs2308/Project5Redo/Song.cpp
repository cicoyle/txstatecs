/****************************************************
Name: Cassandra Coyle
Date: 4/4/17
Problem Number: 5
Hours spent solving the problem: 20
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include "Song.h"

using namespace std;

//constructor (default)
Song::Song() {
	strcpy(artist, " EMPTY ");
	strcpy(title, "EMPTY");
	size = 0;
	pos = 0;
}

// constructor
Song::Song(char *currentTitle, char *currentArtist, int currentSize, int currentPosition) {
	strcpy(title, currentTitle);
	strcpy(artist, currentArtist);
	size = currentSize;
	pos = currentPosition;
}

//set title
void Song::setTitle(char *songT) {
	strcpy(title, songT);
}

//set artist
void Song::setArtist(char *songA) {
	strcpy(artist, songA);
}

//set size
void Song::setSize(int songSi) {
	size = songSi;
}

//set position
void Song::setPosition(int songNumber) {
	pos = songNumber;
}

//get title
const char* Song::getTitle() const {
	return title;
}

//get artist
const char* Song::getArtist() const {
	return artist;
}

//get size
int Song::getSize() const {
	return size;
}

//overload
bool Song::operator > (const Song &s1) {
	bool status;
	if(*title > *s1.title) 
		status = 1;
	else
		status = 0;
	return status;
}

//overload
bool Song::operator < (const Song &s1) {
	bool status;
	if(*title < *s1.title)
		status = 1;
	else
		status = 0;
	return status;
}

//overload
bool Song::operator == (const Song &s1) {
	bool status;
	if(*title == *s1.title)
		status = 1;
	else
		status = 0;
	return status;
}

//overload
bool Song::operator != (const Song &sBlank) {
	bool status;
	if(*title != *sBlank.title)
		status = 1;
	else
		status = 0;
	return status;
}
