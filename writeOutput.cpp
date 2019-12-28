#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "utils.h"

string getOutputFileName(){ 
    return "output.txt";
}

void writeOutputFile(string text){
     ofstream myfile;
     int n = getOutputFileName().length();
     char char_array[n + 1]; 
     strcpy(char_array, getOutputFileName().c_str()); 
     myfile.open (char_array, fstream::app);
     myfile << text << "\n";
     myfile.close();    
}

