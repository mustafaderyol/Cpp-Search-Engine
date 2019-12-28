#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "currentTime.h" 
#include "writeOutput.h"

// minDistance
int minDistance(int x, int y, int z) { 
  return min(min(x, y), z); 
} 

// distance
int getDistance(string mainText, string searchText, int mainTextLength, int searchTextLength) {
    if (mainTextLength == 0) return searchTextLength; 
    if (searchTextLength == 0) return mainTextLength; 
    if (mainText[mainTextLength-1] == searchText[searchTextLength-1]) {              
		return getDistance(mainText, searchText, mainTextLength-1, searchTextLength-1); 
    }
    int val = minDistance ( getDistance(mainText, searchText, mainTextLength, searchTextLength-1), // Ekleme 
					getDistance(mainText, searchText, mainTextLength-1, searchTextLength), // Silme
					getDistance(mainText, searchText, mainTextLength-1, searchTextLength-1) // Degisiklik
				);
	return (val+1); 
}
 
// write Did you mean?
void distanceAlgorithm(string mainText, string searchText, int line) {
     int diffLength = (mainText.length() - searchText.length());
     int searchTextLength = searchText.length();
     for(int i = 0; i < diffLength ; i++){
         string subMainText = mainText.substr(i, searchText.length());
         int distance = getDistance(subMainText, searchText, subMainText.length(), searchText.length());
         int rate = (1 - ((double)distance / (double)subMainText.length())) * 100;
         if(rate >= 75 && rate != 100){ // Benzerlik oran�
	          stringstream foundStr;
              foundStr << "-------------------------> Did you mean this? -> '";
              foundStr << subMainText;
              foundStr << "' - Line: ";
              foundStr << line;
              foundStr << " - Date: ";
              foundStr << getCurrentDate();
              foundStr << " - Match Rate: %";
              foundStr << rate;
		      writeOutputFile(foundStr.str());
        }   
     }
}
