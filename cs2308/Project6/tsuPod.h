/****************************************************
Name: Cassandra Coyle
Date: 4/15/17
Problem Number: 6
Hours spent solving the problem: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include "Song.h"

using namespace std;

class TsuPod {
	private:
		struct ListNode	{
			//song object
			Song s;
			//point to next node
			ListNode *next;
		};
	
		//head
		ListNode *head;

		int memTotal;
		int currentMem;
		int NumberOfSongs;

	public:
		//Constructor
		TsuPod(int);
		//deconstructor
		~TsuPod();
	
		//Functions
		int validateSong(Song);
		int addSong(Song);
	        int removeSong(Song); 
		void showList();
		int sortList();
	        int shuffle();
	        int clearList(); 
	        int getMemTotal();
	    	int getRemainingMem();

};

