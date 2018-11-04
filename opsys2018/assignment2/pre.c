/*
Cassandra Coyle pre.c OpSystems 2018
Lab 1.1

Task:
Read in a list of US state abbreviations and their populations.
10 states max. Enter input through keyboard, display output on screen.
Input ends when an EOF is encountered.
Output state abbreviations whose population is above 10 million.
*/

//imports
#include <stdio.h>
#include <string.h>

//struct 
typedef struct state{
	char name[2];
	int pop;
} state;

//main
int main() {
	//vars
	state populations[10];
	char temparr[2];
	int counter = 0;
	int p;

	//while input is valid
	while((counter < 10) && (scanf("%2s", &*temparr) != EOF)) {
		scanf("%d", &p);
		strcpy(populations[counter].name, temparr);
		populations[counter].pop = p;
		counter++;
	}
	
	//print newline
	printf("\n\n");

	int index = 0;	
	//for print input
	for(index; index < counter; index++) {
		if(populations[index].pop >= 10)
			printf("%s\n", populations[index].name);
	}

	return(0);
}
