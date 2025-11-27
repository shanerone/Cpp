#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    short int hours_;
    short int minutes_;

public:
    Time();
    Time(short int h, short int m);
    Time(const Time& other);

    short int getHours() const;
    short int getMinutes() const;

    void setHours(short int h);
    void setMinutes(short int m);

    Time subtractTime(const Time& other) const;

    string toString() const;

    Time& operator++();           
    Time operator++(int);         
    Time& operator--();           
    Time operator--(int);         

    
    operator int() const;         
    operator bool() const; 
       
    bool operator<(const Time& t) const;
    bool operator>(const Time& t) const;
};
