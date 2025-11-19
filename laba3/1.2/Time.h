#pragma once
#include <string>

using namespace std;

class Time {
private:
    int sec_;
    
    bool isValidSec(int sec) const; 
public:
    Time(int sec);
    
    void setSec(int sec);
    int getSec() const;
    
    void print() const;
    string getTimeString() const;
    
};