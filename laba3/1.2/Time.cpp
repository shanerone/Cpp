#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int sec) {
    setSec(sec);
}

bool Time::isValidSec(int sec) const {
    return sec >= 0;
}

void Time::setSec(int sec) {
    if (isValidSec(sec)) {
        sec_ = sec;
    } else {
        cout << "Enter positive sec!!";
        sec_ = 0;
    }
}

int Time::getSec() const {
    return sec_;
}

string Time::getTimeString() const {
    const int DaySec = 24 * 60 * 60;

    int moreSutok = sec_ % DaySec; //если больше 24 часов
    
    int hours = moreSutok / 3600;
    int ostatok = moreSutok % 3600;
    int minutes = ostatok / 60;
    int second = ostatok % 60;

    string res;

    res += char('0' + hours / 10); //первая цифра и вторая
    res += char('0' + hours % 10);
    res += ":";

    res += char('0' + minutes / 10);
    res += char('0' + minutes % 10);
    res += ":";

    res += char('0' + second / 10);
    res += char('0' + second % 10);

    return res;
}

void Time::print() const {
    cout << "Time: " << getTimeString() << endl;
}
