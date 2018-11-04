//Cassandra Coyle
//OpSystemsFall2018

//libs to include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {


    //redirection flags
    int inputRedirectionFlag, outputRedirectionFlag;
    //vars provided by prof
    char *inputPath, *outputPath, *argv[20], buf[80], n, *p;
    int m, status, inword, continu;
    int READ = 0;
    int WRITE = 1;
    int start[20];
    int counter;
    int pipes;
    pid_t pid;
    int l_pipe[2];
    int r_pipe[2];

    //array to hold arguments
    int argArray[20] = { 0 };

	//while true
    while (1) {

	//assign vars = 0
        inputRedirectionFlag = outputRedirectionFlag = 0;
	inword = m = continu = counter = pipes = pid = 0;
        p = buf;
    
        printf("\nshhh> ");

        //parse
        while ((n = getchar()) != '\n' || continu) {
            if (n == ' ') {
                if (inword) {
                    inword = 0;
                    *p++ = 0;
                }
            }
            else if (n == '\n') continu = 0;
            else if (n == '\\' && !inword) continu = 1;
            else {
                if (!inword) {
                    inword = 1;
                    argv[m++] = p;
                    *p++ = n;
                }
                else
                    *p++ = n;
            }
        } 

        *p++ = 0;
        argv[m] = 0;

        if (strcmp(argv[0], "exit") == 0) exit(0);

        //handle redirection
        while (argv[counter] != 0) {
		//deal with pipe
            if (strcmp(argv[counter], "|") == 0) {
                argv[counter] = 0;
                argArray[pipes + 1] = counter + 1;
                ++pipes;
		//deal with input redirection
            } else if (strcmp(argv[counter], "<") == 0) {
                inputPath = strdup(argv[counter + 1]); 
                argv[counter] = 0;
                argv[counter + 1] = 0;
                inputRedirectionFlag = 1;
		counter++;
		//deal with output redirection
            } else if (strcmp(argv[counter], ">") == 0) {
                outputPath = strdup(argv[counter + 1]);
                argv[counter] = 0;
                argv[counter + 1] = 0;
                outputRedirectionFlag = 1;
		counter++;
            } else {argArray[counter] = counter;}

            ++counter;
        }

	//put for loop var (a) here bc of std=c99 flag issue
        int a;
        for (a = 0; a <= pipes; ++a) {
		//deal with multiple commands
            if (pipes > 0 && a != pipes) { 
		//no more left pipe. Right pipe becomes next child's left pipe
                pipe(r_pipe); 
            }

            //deal with processes
            switch (pid = fork()) {
                //error
                case -1: perror("fork failed");
                         break;
		//child process
                case 0: 
			//deal with input redirection
                       if ((a == 0) && (inputRedirectionFlag == 1)) {
                           int inputFileDescriptor = open(inputPath, O_RDONLY , 0400);
                           if (inputFileDescriptor == -1) {
                               perror("input file did not open\n");
                               return(EXIT_FAILURE);
                           }
                           close(READ);
                           dup(inputFileDescriptor);
                           close(inputFileDescriptor);
                       } 
			//deal with output redirection
                       if ((a == pipes) && (outputRedirectionFlag == 1)) {
                           int outputFileDescriptor = open(outputPath, O_WRONLY | O_CREAT, 0755);
                           if (outputFileDescriptor < 0) {
                               perror("output file failed to open\n");
                               return(EXIT_FAILURE);
                           }
                           close(WRITE);
                           dup(outputFileDescriptor);
                           close(outputFileDescriptor);
                       } 
			//deal with pipes
                        /* manage pipes if (a) first child process, (b) middle child process, or (c) third/final child process */
			if (pipes > 0) {
				//deal with first child process
                            if (a == 0){ 
                                close(WRITE);
                                dup(r_pipe[WRITE]);
                                close(r_pipe[WRITE]);
                                close(r_pipe[READ]);
				//deal with middle (2nd) child process
                            } else if (a < pipes) {
                                close(READ);
                                dup(l_pipe[READ]);
                                close(l_pipe[READ]);
                                close(l_pipe[WRITE]);
                                close(WRITE);
                                dup(r_pipe[WRITE]);
                                close(r_pipe[READ]);
                                close(r_pipe[WRITE]);
				//deal with last (3rd) child process
                            } else {
                                close(READ);
                                dup(l_pipe[READ]);
                                close(l_pipe[READ]);
                                close(l_pipe[WRITE]);
                            }
                        }

                       //run the execute command
                       execvp(argv[argArray[a]], &argv[argArray[a]]);
                       //check if execute command fails
                       perror("Command execution (execvp) failed\n");

                       break;
		
		//parent process deals with the pipes for the child processes
                default:
                        if (a > 0) {
                            close(l_pipe[READ]);
                            close(l_pipe[WRITE]);
                        }
                        l_pipe[READ] = r_pipe[READ];
                        l_pipe[WRITE] = r_pipe[WRITE];

                        //parent waits for child process
                        wait(&status);

                        break;
            } 
        } 

	//put for loop var (b) here bc of std=c99 flag issue
	int b;
        //For loop to run thru and clear the executed commands
        for (b = 0; b < 20; ++b) {
            argv[b] = 0;
        }
    }
}
