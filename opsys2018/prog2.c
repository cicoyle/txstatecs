//Cassandra Coyle problem #2 HW #1 OpSystem 2018
//Lab 1.2
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main() {
	int p [2];
	int bytes;
	pid_t pid;
	//fork first so you have a p and c process
	pid = fork();
	//pipe next so p and c share pipe
	pipe(p);
	
	if(pid < 0) 
		exit(1);
	else if(pid == 0) {
		close(1);
		dup(p[1]);
		close(p[0]);
		close(p[1]);
		//execute pre
		execl("./pre", "pre", (char *) 0);
		return(EXIT_FAILURE);
	} 
	else {
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		execl("./sort", "sort", (char *)0);
		return(EXIT_FAILURE);
	}

	return (0);
}
