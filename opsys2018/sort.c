/*
Cassandra Coyle sort.c OpSystems 2018
Lab 1.2 

Task:
Read in a list of state abbreviations from stdin and display them in alphabetical order on screen.
10 states max.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//struct
struct state{
	char stateName[10];
};

//compare state abbreviations
static int compare(const void *a, const void *b) {
	struct state *ia = (struct state *)a;
	struct state *ib = (struct state *)b;
	return strcmp(ia -> stateName, ib -> stateName);
}

//main
int main() {
	const int SIZE = 10;
	struct state states[SIZE];
	int index = 0;
	memset(&states, 0, sizeof(states));
	
	index = 0;
	//while valid sort and then print
	while(scanf("%s", states[index].stateName) != EOF && index++ < SIZE) {}
	index = 0;
	qsort(states, SIZE, sizeof (struct state), compare);
	while(index < SIZE) {
		printf("%s\n", states[index].stateName);
		index++;
	}	

	return 0;
}
