#include "Time.h"

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(short int h, short int m) {
    setHours(h);
    setMinutes(m);
}

Time::Time(const Time& other) {
    hours_ = other.hours_;
    minutes_ = other.minutes_;
}

short int Time::getHours() const {
    return hours_;
}

short int Time::getMinutes() const {
    return minutes_;
}

void Time::setHours(short int h) {
    if (h >= 0 && h <= 23) {
        hours_ = h;
    } else {
        cout << "Invalid hours!\n";
        hours_ = 0;
    }
}

void Time::setMinutes(short int m) {
    if (m >= 0 && m <= 59) {
        minutes_ = m;
    } else {
        cout << "INvalid minutes\n";
        minutes_ = 0;
    }
}

Time Time::subtractTime(const Time& other) const {
    int totalMinutes1 = hours_ * 60 + minutes_;
    int totalMinutes2 = other.hours_ * 60 + other.minutes_;
    
    int result = totalMinutes1 - totalMinutes2;
    
    if (result < 0) {
        result += 24 * 60;
    }
    
    short int resHours = result / 60;
    short int resMinutes = result % 60;
    
    return Time(resHours, resMinutes);
}

string Time::toString() const {
    string result = "";
    
    if (hours_ < 10) result += "0";
    result += to_string(hours_);
    
    result += ":";
    
    if (minutes_ < 10) result += "0";
    result += to_string(minutes_);
    
    return result;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.toString(); 
    return os;
}