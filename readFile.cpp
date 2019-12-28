#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <bitset>
using namespace std; 
#include "searchAlgorithm.h"
#include "distanceAlgorithm.h"
#include "writeOutput.h"
#include "utils.h"

void readFile(string filePath, string searchText){
     fstream newfile;
     int n = filePath.length();
     char char_array[n + 1]; 
     strcpy(char_array, filePath.c_str()); 
     newfile.open(char_array, ios::in); 
     if (newfile.is_open()){
         string tp;
         int line = 1;
         while(getline(newfile, tp)){
	        searchAlgorithm(tp, searchText, line);
	        searchAlgorithm(tp, toLowerString(searchText), line);
	        searchAlgorithm(tp, toUpperString(searchText), line);
	        distanceAlgorithm(tp, searchText, line);
	        distanceAlgorithm(tp, toLowerString(searchText), line);
	        distanceAlgorithm(tp, toUpperString(searchText), line);
	        line++;
         }
         newfile.close();
     }
}
