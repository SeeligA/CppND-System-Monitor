#include <string>
//
#include <cmath>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    char buffer [12];
    int h, m;    
    // Convert to int to avoid Make warning related to sprintf call;
    int s = seconds;
    
    h = floor(s/3600);    
    s = s % 3600;
    m = floor(s/60);    
    s = s % 60;  

    sprintf(buffer, "%02d:%02d:%02d\n", h, m, s);
    return buffer; 
}