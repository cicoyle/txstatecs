/****************************************************
Name: Cassandra Coyle
Date: 4/15/17
Problem Number: 6
Hours spent solving the problem: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include "tsuPod.h"
#include <ctime>
#include <cstring>

using namespace std;

//constructor
TsuPod::TsuPod(int memory) {
	//assign variables
	memTotal = memory;
	head = NULL;
	currentMem = 0;
	NumberOfSongs = 0;
}

//deconstructor
TsuPod::~TsuPod() {}

//validate song being added
int TsuPod::validateSong(Song CassieSong) {
	//validate size
	if(0 > CassieSong.getSize()) {
		cout << "Error. Song not added. Size needs to be greater than 0." << endl;
		return -2;
	}
	//validate size
	if(getRemainingMem() < CassieSong.getSize()) {
		cout << "Error. Song not added. Size is too big." << endl;
		return -2;
	}

	//validate that the title and artist is not blank
	if(CassieSong.getTitle() == " " || CassieSong.getArtist() == " ") {
		cout << "Error. Song not added. Title/Artist cannot be blank." << endl;
		return -3;
	}

	//validate memory space
	if(getRemainingMem() < CassieSong.getSize()) {
		cout << "Error. Song not added. Not enough memory." << endl;
		return -5;
	}
}

//function to add song to playlist
int TsuPod::addSong(Song CassieSong) {
	//validate the song being added
 	if(validateSong(CassieSong) < 0)
                return -1;
	
	//pointers
	ListNode *traversalPtr;
	ListNode *newNode;	
	
	//allocate memory
	newNode = new ListNode;

	//assign new node 
	newNode -> s = CassieSong;
	newNode -> next = NULL;

	//increment song count
	NumberOfSongs++;	

	//calculate total memory
	currentMem += CassieSong.getSize();	
	
	//if empty head is first node
	if(head == NULL)
		head = newNode;

	else {
		//assign pointer to head
		traversalPtr = head;

		//traverse to find last node
		while(traversalPtr -> next != NULL)
			traversalPtr = traversalPtr -> next;

		//assign last node
		traversalPtr -> next = newNode;
	}//close else

	return 0;
}

//function to remove song
int TsuPod::removeSong(Song CassieSong) {
	//variable for song to be removed
	bool songFound = false;
	
	//traversal & previous pointers
	ListNode *previousNode;
	ListNode *traversalPtr;

	//assign pointers
	previousNode = NULL;
	traversalPtr = head;	

	//while song is not found
	while(songFound == false) {

		//check if the head is null
		if(head == NULL) {
			cout << "ERROR. List is empty." << endl;
			return -1;
		}//close if

		else if(head -> s == CassieSong) {
			//assign traversal ptr
			traversalPtr = head -> next;

			//delete the head
			delete head;

			//assign head
			head = traversalPtr;

			//assign song found
			songFound = true;
		}//close else if

		else { 
			//assign traversal ptr
			traversalPtr = head;

			//while the traversal ptr is not null
			// and while traversal ptr is not the song
			while(traversalPtr != NULL && traversalPtr -> s != CassieSong) {
				//assign previous node
				previousNode = traversalPtr;

				//assign traversal ptr
				traversalPtr = traversalPtr -> next;
			}//close else

			//check if traversal ptr is not null
			if(traversalPtr != NULL) {
				//assign previous nodes next to traversal prts next
				previousNode -> next = traversalPtr -> next;

				//delete traversal ptr
				delete traversalPtr;

				//assign song found
				songFound = true;

			}//close if

		}//close else

	}//close while

	//if the song is found
	if(songFound) {
		//decrement number of songs
		NumberOfSongs--;	

		//assign current memory
		currentMem -= CassieSong.getSize();
	}//close if
	
	return 0;
}

//Function to sort the playlist
int TsuPod::sortList() {
	//pointers
	ListNode *traversalPtr;
	ListNode *basePtr;
	
	//temp variable
	Song tempVar;
	
	basePtr = head;

	//for loop to assign base ptr to head, base ptrs next is not null, base ptr is base ptrs next
	for(basePtr = head; basePtr -> next != NULL; basePtr = basePtr -> next) {
		//assign traversal ptr to base ptr
		traversalPtr = basePtr -> next;

		//if base ptrs song is bigger than traversal ptrs song
		if(basePtr -> s > traversalPtr -> s) {
			tempVar = basePtr -> s;
			basePtr -> s = traversalPtr -> s;
			traversalPtr -> s = tempVar;

		}//close if

	}//close for

	return 0;
}

//shuffle songs
int TsuPod::shuffle() {
	//variables
	int number = 0;
	Song tempVar;	

	//pointers
	ListNode *traverse;
	ListNode *swap;
	ListNode *previous;

	//assign nodeptr
	ListNode *nodePtr = head;
	
	//if head is null
	if(head == NULL) {
		cout << "Error. list is empty." << endl;
		return -2;
	}//close if

	//for loop to go through numberofsongs
	for(int i = 0; i < NumberOfSongs; i++) {
		//assign number to random number
		srand(time(0));
		number = (rand() % NumberOfSongs);
	
		//initialize
		traverse = head;
		previous = nodePtr;

		//inner for loop
		for(int a = 1; a <= number; a++) {
			//check if number
			if(a == number) 
				swap = traverse;
			//assing traverse
			traverse = traverse -> next;
		}
		
		//swap
		//assign temp variable
		tempVar = previous -> s;
		previous -> s = swap -> s;
		swap -> s = tempVar;
		//assign nodeptr
		nodePtr = nodePtr -> next;
	}
	return 0;
}

//function to show song list
void TsuPod::showList() {
	//pointer & assign to head
	ListNode *traversalPtr;
	traversalPtr = head;
	
	//while traversing through list
	while(traversalPtr != NULL) {
		cout << traversalPtr -> s.getTitle() << " By: "
		     << traversalPtr -> s.getArtist() << " "
		     << " Size: : " << traversalPtr -> s.getSize()
		     << " MB" << endl;
		//assign traversal ptr
		traversalPtr = traversalPtr -> next;
	}//close while

}

//function to get the total memory
int TsuPod::getMemTotal() {
	return memTotal;
}

//function to get the remaining memory
int TsuPod::getRemainingMem() {
	return (getMemTotal() - currentMem);
}

//function to clear song list
int TsuPod::clearList() {
	//pointer
	ListNode *traversalPtr;
	
	//assign ptr to head
	traversalPtr = head;
	
	//assign mem and number of songs to 0
	currentMem = 0;
	NumberOfSongs = 0;
	
	//while traversal ptr is not null
	while(traversalPtr != NULL) {
		//heads next is traversal ptrs next
		head -> next = traversalPtr -> next;
		//traversals next is null
		traversalPtr -> next = NULL;
		//delete traversal ptr
		delete traversalPtr;
		//assign traversal ptr
		traversalPtr = head -> next;
	}//close while

	//assign head to null
	head = NULL;

	return 0;
}
