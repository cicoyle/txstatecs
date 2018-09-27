/*
Cassandra Coyle
Lab 1 Problem 3

Task:
Write program to take UNIX command from command line and fork() a child to execute it.
The command can be as simple as &ls or $ps, or more complex like $ls -t -l.
Use argc and argv[] in main to pass parameters. When child process is done executing
the command, the parent process simply waits for the termination of the child process. 
The process ID (pid) of the parent and the child should be printed out using getpid()
and getppid() functions.
*/

//imports
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

//main
int main(int argc, char **argv) {
	//vars
	int pid;
	int status;

	//fork the child and set it to pid
	pid = fork();

	//error
	if(pid < 0) {
		printf("Error forking. \n");
		exit(1);
	}//parent process 
	else if(pid ==0) {
		printf("Child process started. \n");
		printf("Executing %s command: ", argv[1]);
		printf("Outputted command: ");
		system(argv[1]);
		printf("\n");
	}//child process
	else {
		printf("Parent process started. \n");
		wait((int *)0);
		wait(&status);
		printf("\n");
		printf("Parent process done.");
		printf("\n");
		printf("Child pid : %d & Parent pid : %d", getpid(), getppid());
		printf("\n");
	}

	return 0;
}
		
