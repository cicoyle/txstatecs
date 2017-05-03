/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 10
Instructor: Komogortsev, TSU
*****************************************************/
#include <fstream>
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>
#include "thisStack.h"

using namespace std;

int main(int argc, char* argv[]) {                                                                                                                       
        //create stack object                                                                                                                            
        stack mainStack(300);                                                                                                                            
                                                                                                                                                         
        //file objects                                                                                                                                   
        ofstream fout;                                                                                                                                   
        ifstream fin;                                                                                                                                    
                                                                                                                                                         
        //open output file                                                                                                                               
        fout.open("exp_output.dat", ios::app);                                                                                                           
                                                                                                                                                         
        //validate that output file opened                                                                                                               
        if(!fout) {                                                                                                                                      
                cout << "Error. Output file didn't open" << endl;                                                                                        
                return -1;                                                                                                                               
        }                                                                                                                                                
                                                                                                                                                         
        //variables                                                                                                                                      
        string userFileName;                                                                                                                                 
        string tempVar;                                                                                                                              
        char * fileLine;                                                                                                                                 
                                                                                                                                                         
        //prompt user for file name                                                                                                                      
        cout << "Enter file name: ";                                                                                                                     
        cin >> userFileName;                                                                                                                                 
                                                                                                                                                         
        //open input file                                                                                                                                
        fin.open(userFileName.c_str());                                                                                                                      
                                                                                                                                                         
        //validate that input file opened                                                                                                                
        if(!fin) {                                                                                                                                       
                cout << "Error. Input file didn't open" << endl;                                                                                         
                return -1;                                                                                                                               
        }                                                                                                                                                
                                                                                                                                                         
        //while loop to get each line of the input file                                                                                                  
          while(getline(fin,tempVar)) {                                                                                                              
                //variables                                                                                                                              
                int lP;                                                                                                                              
                int lB;                                                                                                                              
                int rP;                                                                                                                              
                int rB;                                                                                                                              
                int P;                                                                                                                               
                int B;                                                                                                                               
                
		//assign variables to zero
		lP = lB = rP = rB = P = B = 0;     
		                                                                                                                                    
                //assign size                                                                                                                            
                int size = tempVar.length();                                                                                                         
                                                                                                                                                         
                //allocate memory                                                                                                                        
                fileLine = new char[size];                                                                                                               
                                                                                                                                                         
                                                                                                                                                         
                //string copy                                                                                                                            
                strcpy(fileLine, tempVar.c_str());                                                                                                   
                                                                                                                                                         
                fout << fileLine << " ";                                                                                                                 
                                                                                                                                                         
                //for loop to run through the size of the array                                                                                          
                for(int i = 0; i < size; i++) {                                                                                                          
                        //check if the index is a (                                                                                                      
                        if(fileLine[i] == '(')                                                                                                           
                                lP++;                                                                                                                    
                                                                                                                                                         
                        //check if the index is a [                                                                                                      
                        else if(fileLine[i] == '[')                                                                                                      
                                lB++;                                                                                                                    
                                                                                                                                                         
                        //check if the index is a )                                                                                                      
                        else if(fileLine[i] == ')')                                                                                                      
                                rP++;                                                                                                                    
                                                                                                                                                         
                        //check if the index is a ]                                                                                                      
                        else if(fileLine[i] == ']')                                                                                                      
                                rB++;                                                                                                                    
                }                                                                                                                                        
                                                                                                                                                                                                                                                                                                
                //calculate the number of brackets
		B = rB + lB;                                                                                                                             
                                                                                                                                                         
                //calculate the number of parenthesis                                                                                                    
                P = rP = lP;                                                                                                                             
                                                                                                                                                         
                //check if the function is true, thus the line is valid                                                                                  
                if(mainStack.checkBalance(fileLine) == true)                                                                                             
                        fout << " === valid expression";                                                                                                 
                                                                                                                                                         
                //if line is not valid                                                                                                                   
                else {                                                                                                                                   
                        fout << " === missing: ";                                                                                                        
                                                                                                                                                         
                        //variables                                                                                                                      
                        bool bFlag = false;                                                                                                        
                        bool pFlag = false;                                                                                                    
                                                                                                                                                         
                                                                                                                                                         
                        //check if the B are not equal                                                                                                   
                        if(lB != rB)                                                                                                                     
                                bFlag = true;                                                                                                      
                                                                                                                                                         
                        //check if the parenthesis are not equal                                                                                         
                        if(lP != rP)                                                                                                                     
                                pFlag = true;                                                                                                  
                                                                                                                                                         
                        //if flag is true                                                                                                                
                        if(bFlag) {                                                                                                                
                                //display the missing bracket                                                                                            
                                if(rB > lB)                                                                                                              
                                        fout << (rB - lB) << " [ ";                                                                                      
                                if(lB > rB)                                                                                                              
                                        fout << (lB - rB) << " ] ";                                                                                      
                        }                                                                                                                                
                                                                                                                                                         
                        //if flag is true                                                                                                                
                        if(pFlag) {                                                                                                            
                                //display the missing parenthesis                                                                                        
                                if(rP > lP)                                                                                                              
                                        fout << (rP - lP) << " ( ";                                                                                      
                                if(lP > rP)                                                                                                              
                                        fout << (lP - rP) << " ) ";                                                                                      
                        }                                                                                                                                
                                                                                                                                                         
                        //if the flags are false                                                                                                         
                        if(!bFlag && !pFlag) {                                                                                           
                                //display the missing bracket                                                                                            
                                if((lB == rB) &&                                                                                                         
                                        (lB != 0) && (rB != 0))                                                                                          
                                        fout << rB << " ] " << lB << " [ ";                                                                              
                                //display the missing parenthesis                                                                                        
                                if((lP == rP) && (lP != 0) && (rP != 0))                                                                                 
                                        fout << rP << " ) " << lP << " ( ";                                                                              
                        }                                                                                                                                
                                                                                                                                                         
                        if((lB + rB + lP + rP) > 6)                                                                                                      
                                fout << "    Error: More than 6 missing elements ";                                                                      
                }                                                                                                                                        
                                                                                                                                                         
                fout << endl;                                                                                                                            
        } //close while loop                                                                                                                             
                                                                                                                                                         
        return 0;                                                                                                                                        
}                                                                                                                                                        
