#include <iostream>
#include <fstream>
using namespace std; 
#include "searchFiles.h"
#include "writeOutput.h"
#include "utils.h"

int main() { 
    setlocale(LC_ALL, "Turkish"); 
    // Search Path
    string filePath = "./deneme/";
	// Output File
	string outputFileName = getOutputFileName();
    int n = outputFileName.length();
    char charOutputFileName[n + 1]; 
    strcpy(charOutputFileName, outputFileName.c_str()); 
    fstream file;
    remove(charOutputFileName);
    file.open(charOutputFileName, ios::out); 
    if(!file) { 
       cout<<"Error in creating file!!!"; 
	   system("pause");
	   return 0; 
    } 
    file.close(); 
    // Cin>> Search Text
    string searchText;
    int count = 0;
    do {
       system ("CLS");
       if(count != 0){
          cout<<"Min 3 karakter giriniz!"<<endl;
       }
       count++;
       cout<<"Lütfen aramak istediðiniz metni giriniz: "<<endl;
       cin>>searchText;
    } while(searchText.length() < 3);
    // Search Files
	searchFiles(filePath, searchText);
	// Run Output File
	string fileNeededtoBeOpened = "START .\\\""+outputFileName+"\"";
    system(fileNeededtoBeOpened.c_str());
    //system ("pause");
	return 0; 
} 
