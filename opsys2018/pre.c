//Cassandra Coyle pre.c OpSystems 2018
//Lab 1.1
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
//	int index = 0;

	//while input is valid
	while((counter < 10) && (scanf("%2s", &*temparr) != EOF)) {
		scanf("%d", &p);
		strcpy(populations[counter].name, temparr);
		populations[counter].pop = p;
		counter++;
	}
	
	//print newline
	printf("\n\n");

	
	//for print input
	for(int index = 0; index < counter; index++) {
		if(populations[index].pop >= 10)
			printf("%s\n", populations[index].name);
	}

	return(0);

}
