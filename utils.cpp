#include <iostream> 
#include <cstring> 
using namespace std; 

string toLowerString(string text){
   int length = text.length(); 
   for (int i = 0; i < length; i++) { 
      int c = text[i];
      text[i] = tolower(c);         
   }
   return text;
}

string toUpperString(string text){
   int length = text.length(); 
   for (int i = 0; i < length; i++) { 
      int c = text[i]; 
      text[i] = toupper(c);         
   }
   return text;
}

char* toChar(string text){
    int n = text.length();
    char char_array[n + 1]; 
    strcpy(char_array, text.c_str()); 
    return char_array;
}
