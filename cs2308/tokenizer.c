#include <stdio.h>
#include <stdlib.h>
void getToken(char, int, char*);

int main(int argc, char *argv[]) {

	printf("toakenizer, v1\nusage - ./a.out [input_file] <delimiter> <position>");

	FILE *inputText;

        inputText = fopen(argv[1], "r");

	int pos = atoi(argv[3]);
	char* delim = argv[2];

	if(inputText == NULL){
		fprintf(stderr,"fucked up, no file\n");
		return -1;
	}
	else { printf("tokenizing %s file; passed args: delim=%d; looking for element in pos.: %i\n", argv[1], argv[2][0], pos); }

	char* buffer;
	buffer = malloc(sizeof(char)*128);

	fgets(buffer, 128, (FILE *)inputText);

	getToken(*delim, pos, buffer);

	fclose(inputText);
free(buffer);

	return 0;

}


void getToken(char delim, int pos, char* buf){
char* iterator = buf;
int count = 0;
	while(*iterator++ && (count != pos)){
	if(*iterator==delim)
		count++;
	while(*iterator==delim)
		iterator++;
	}

	iterator--;
while(*iterator && *iterator != delim)
printf("%c", *iterator++);
printf("\n");
}
