#include <iostream>
#include <sstream>
using namespace std;
#include "currentTime.h" 
#include "writeOutput.h"

// fonsiyon tan�m� yap�ld�
void computeLPSArray(string searchText, int M, int* lps); 

//Search metodu -> Knuth�Morris�Pratt Algorithm
void searchAlgorithm(string mainText, string searchText, int line) 
{ 
	int searchTextLength = searchText.length(); 
	int mainTextLength = mainText.length(); 
	int lps[searchTextLength]; 
	computeLPSArray(searchText, searchTextLength, lps); 
	int mainTextIndex = 0;
	int searchTextIndex = 0;
	while (mainTextIndex < mainTextLength) { 
		if (searchText[searchTextIndex] == mainText[mainTextIndex]) { 
			searchTextIndex++; 
			mainTextIndex++; 
		} 
		if (searchTextIndex == searchTextLength) { // Eslesme sagland�
		    stringstream foundStr;
            foundStr << "------------------------->";
            foundStr << " Line: ";
            foundStr << line;
            foundStr << " - Index: ";
            foundStr << (mainTextIndex - searchTextIndex);
            foundStr << " - Date: ";
            foundStr << getCurrentDate();
		    writeOutputFile(foundStr.str());
			searchTextIndex = lps[searchTextIndex - 1]; 
		} else if (mainTextIndex < mainTextLength && searchText[searchTextIndex] != mainText[mainTextIndex]) { //Eslesen kay�t yok ise
			if (searchTextIndex != 0) {
				searchTextIndex = lps[searchTextIndex - 1]; 
            } else {
				mainTextIndex = mainTextIndex + 1; 
            }
		} 
	} 
} 


// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string searchText, int searchTextLength, int* lps) 
{ 
	int len = 0; 
	lps[0] = 0;
	int i = 1; 
	while (i < searchTextLength) { 
         int temp = i ;
		if (searchText[i] == searchText[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} else { 
			if (len != 0) { 
				len = lps[len - 1]; 
			} else { 
				lps[i] = 0; 
				i++; 
			} 
		}
	} 
}
