//Cassandra Coyle
//Project 3 assignment 1

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>


//award struct
struct Award {
	int givenAmt;
	int currentAwardAmt;
};

//functions
void student(char stud);

//vars
struct Award award;

//main function to be executed
int main() {

	//initialize vars
	award.givenAmt = 0;
	award.currentAwardAmt = 4000;

	//tread IDs
	pthread_t tid1, tid2, tid3;
	
	//create threads
	pthread_create(&tid1, NULL, (void*(*)(void*))student, (void*) '1');
	pthread_create(&tid2, NULL, (void*(*)(void*))student, (void*) '2');
	pthread_create(&tid3, NULL, (void*(*)(void*))student, (void*) '3');

	//join the threads
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	//print out the amount of money given out
	printf("Total given out $%d \n", award.givenAmt);
	
	//exit status
	pthread_exit(0);
	
}

//function to deal with threads~students
void student(char stud) {
	
	//initialize var
	int tmp;
	int Amt = 0;

	//while there is $ to give
	while(0 < award.currentAwardAmt) {

		//assign the tmp var to the ceiling of the current award amount using ceil()
		tmp = ceil(award.currentAwardAmt*(.25));

		//calculations
		award.currentAwardAmt = award.currentAwardAmt - tmp;
		Amt = tmp + Amt;

		//print outcome
		printf("%c = %d \n",stud, tmp);
		
		//slow down threads using sleep
		sleep(3);
	}
	
	//calculate the given out amount	
	award.givenAmt += Amt;
}
