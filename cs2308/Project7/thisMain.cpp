/****************************************************
Name: Cassandra Coyle
Date: 4/27/2017
Problem Number: 7
CS2308
Hours worked on project: 21
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
        ifstream fin;                                                                                                                                    
        ofstream fout;                                                                                                                                   
                                                                                                                                                         
        //open output file                                                                                                                               
        fout.open("exp_output.dat", ios::app);                                                                                                           
                                                                                                                                                         
        //validate that output file opened                                                                                                               
        if(!fout) {                                                                                                                                      
                cout << "Error. Output file didn't open" << endl;                                                                                        
                return -1;                                                                                                                               
        }                                                                                                                                                
                                                                                                                                                         
        //variables                                                                                                                                      
        char * fileLine;                                                                                                                                 
        string tempVar;                                                                                                                              
        string userFileName;                                                                                                                                 
                                                                                                                                                         
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
                
		//assign variables to zero
		lP = lB = rP = rB = 0;     
		                                                                                                                                    
                //assign size                                                                                                                            
                int size = tempVar.length();                                                                                                         
                                                                                                                                                         
                //allocate memory                                                                                                                        
                fileLine = new char[size];                                                                                                               
                                                                                                                                                         
                                                                                                                                                         
                //string copy                                                                                                                            
                strcpy(fileLine, tempVar.c_str());                                                                                                   
                                                                                                                                                         
                fout << fileLine << " ";                                                                                                                 
                                                                                                                                                         
                 //variables                                      
		 bool pFlag = false;
		 bool bFlag = false;
                                                                                                    
                //for loop to run through the size of the array                                                                                          
                for(int i = 0; i < size; i++) {                                                                                                          
			//check if the index is a (                                                                                                      
                        if((*(fileLine + i)) == '(')                                                                                                           
                                lP++;  
                                                                                                                  
                        //check if the index is a )                                                                                                      
                        else if((*(fileLine + i)) == ')')                                                                                                      
                                rP++;   
                                                                                                                 
                        //check if the index is a ]                                                                                                      
                        else if((*(fileLine + i)) == ']')                                                                                                      
                                rB++; 
                                                                                                                                                         
                        //check if the index is a [                                                                                                      
                        else if((*(fileLine + i)) == '[')                                                                                                      
                                lB++;                                                                                                                    
                                                                                                                                                         
			if(lP < rP)
				pFlag = true;                                                                                                             
		
			if(lB < rB)
				bFlag = true;
                }                                                                                                                                         
                                                                                                                                                         
                //check if the function is true, thus the line is valid                                                                                  
                if(mainStack.checkElementsBalanced(fileLine) == true)                                                                                             
                        fout << " === valid expression";                                                                                                 
                                                                                                                                                         
                //if line is not valid                                                                                                                   
                else {  
			bool sixErrorFlag = false;

			//calculate the total brackets and parenthesis               
			int totalElements = (lB + rB + lP + rP);                                                                                                			
			//check for more than 6 missing elements                              
                        if(totalElements > 6) {                                                                                                     
               			sixErrorFlag = true;
                                fout << " === Error. There are more than 6 missing elements ";                                                         
			}
			
			if(!sixErrorFlag) {
                        	fout << " === missing: ";                                                                                                                                   
				//variables
				int lBBigger = lB - rB;
				int rBBigger = rB - lB;
                       		
				 //check if the brackets are not equal                                     
				 if(rB != lB) {      
					if(rB < lB)
						fout << lBBigger << " ] ";
					if(lB < rB)
						fout << rBBigger << " [ ";
				}

				//variables
				int lPBigger = lP - rP;
				int rPBigger = rP - lP;                                                
                                                                                                         
                        	//check if the parenthesis are not equal                                                                     
                        	if(rP != lP) {
					if(rP < lP)
						fout << lPBigger << " ) ";
					if(lP < rP)
						fout << rPBigger << " ( ";                                                                 
                                }                                                                     
                                   
				//variables
				bool bEqualFlag = false;
				bool pEqualFlag = false;
				
				if(rB == lB)
					bEqualFlag = true;
				if(rP == lP)
					pEqualFlag = true;
				
				if((bEqualFlag = true) && (pEqualFlag = true)) {
					if((rP != 0) && (lP != 0) && pFlag)
						fout << rP << " ) " << lP << " ( ";
					if((rB != 0) && (lB != 0) && bFlag)
						fout << rB << " ] " << lB << " [ ";
				}
                                                                                                                      
               		} //close if

		} //close else                                                                                                                                                                                                                                                                                                
                fout << endl;                                                                                                                            

        } //close while loop                                                                                                                             
                                                                                                                                                         
        return 0;                                                                                                                                        
} //close main                                                                                                                                                        
