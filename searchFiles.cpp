#include <iostream>
#include <dirent.h> 
using namespace std; 
#include <sys/stat.h>
#include "writeOutput.h"
#include "readFile.h"

void search(string drct, string prefix, string searchText){
    string filepath;
    struct dirent *de;
    struct stat filestat;
    int n = drct.length();
    char char_array[n + 1]; 
    strcpy(char_array, drct.c_str()); 
	DIR *dr = opendir(char_array); 
	while ((de = readdir(dr)) != NULL) {
        filepath = drct + "/" + de->d_name;
        string nameString(de->d_name);
        if(nameString == "." || nameString == ".."){
            continue;
        }
	    if (strstr(de->d_name, ".xml") || strstr(de->d_name, ".csv") || strstr(de->d_name, ".txt") || strstr(de->d_name, ".html")) {
            writeOutputFile(prefix + de->d_name);
            readFile((drct + "/"+ de->d_name), searchText);
            continue;
        } 
        if (stat(filepath.c_str(), &filestat)) {
            continue;
        }
        writeOutputFile(prefix + "[ " + de->d_name + " ]");
        if (S_ISDIR(filestat.st_mode)) {
            search(drct + "/"+ de->d_name ,prefix + "|----", searchText);
        }
    }
	closedir(dr);
}

void searchFiles(string drct, string searchText){
     search(drct, "|----", searchText);
}
