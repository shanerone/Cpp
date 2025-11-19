#pragma once

#include <iostream>
#include <string>

using namespace std;

class Time {
private:
    int sec_;

    bool isValidSec(int sec) const;
    bool isValidTime(int hours, int minutes, int seconds) const;

public:
    Time(int sec);
    Time(int hours, int minutes, int seconds);

    void setSec(int sec);
    int getSec() const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void print() const;
    string getTimeString() const;
};
