//Cassandra Coyle sort.c OpSystems 2018
//Lab 1.2 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//struct
struct st_ex {
	char name[3];
};

//str compare function
int compare_by_state(const void *a, const void *b) {
	struct st_ex *ia = (struct st_ex *)a;
	struct st_ex *ib = (struct st_ex *)b;
	//return statement
	return strcmp(ia -> name, ib -> name);
}

//main
int main(int argc, char **argv) {
	//check if argc is valid
	if(argc > 11) {	
		printf("%s", "too many states were entered");
		exit(1);
	} 
	else {
		struct st_ex structs[argc - 1];
		//for to run through up to argc and strcpy
		for(int i = 1; i < argc; i++) 
			strcpy(structs[i].name, argv[i]);

		//get size
		size_t structs_len = sizeof(structs) / sizeof(struct st_ex) + 1;
		//sort
		qsort(structs, structs_len, sizeof(struct st_ex), compare_by_state);
		//for to run through up to argc and printf
		for(int i = 1; i < argc; i++)
			printf("%s\n", &*structs[i].name);
	}
	//return value
	return (0);
}	
