#include <iostream>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std; 

string getCurrentDate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream date;
    date << ltm->tm_mday
         << "/"
         << 1 + ltm->tm_mon
         << "/"
         << 1900 + ltm->tm_year
         << " "
         << 1 + ltm->tm_hour
         << ":"
         << 1 + ltm->tm_min
         << ":"
         << 1 + ltm->tm_sec;
   return date.str();
}
