#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time{
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

    string toString() const;
    
    friend ostream& operator<<(ostream& os, const Time& time);
    Time subtractTime(const Time& other) const;
};
