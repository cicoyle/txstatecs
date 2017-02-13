/***********************************
Name: Cassandra Coyle
Date: 2/14/17
Problem Number: 02
Hours spent solving the problem:
Instructor: Komogortsev, TSU
************************************/
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

//prototypes
int validatefiles();
int parse(char array1[], char array2[]);

ifstream fin;
ofstream fout;

int main()
{
	fin.open("student_input.dat");
	fout.open("student_results.dat");
	validatefiles();

	//variables
	const int size = 256;
	char studentinfo[size];
	char firstname[11] = {0,0,0,0,0,0,0,0,0,0,0};
	char lastname[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int ID[7] = {0};
	int test1[5] = {0};
	int test2[5] = {0};
	int test3[5] = {0};
	int test4[5] = {0};
	int test5[5] = {0};
	int test6[5] = {0};

	while(!fin.eof())
	{
		fin.getline(studentinfo, size);
		cout << studentinfo << endl;
		parse(studentinfo, firstname, counter);
		parse(studentinfo, lastname);
	}

	fin.close();
	fout.close();
	return 0;
}
//validate that files open
int validatefiles()
{
	if(!fin)
	{
		cout << "Error! Input file did not open.";
		return 1;
	}
	if(!fout)
	{
		cout << "Error! Output file did not open.";
		return 1;
	}

}
int parse(char array1[], char array2[])
{
	int i = 0;

	while(array1[i] != ' ' || array1[i] !=  '\t')
	{
		array1[i++] = array2[i++];	
		cout << array1 << endl << array2;
	}


}

