#include "Time.h"
#include <iostream>

using namespace std;

bool Time::isValidSec(int sec) const {
    return sec >= 0 && sec < 86400;
}

bool Time::isValidTime(int hours, int minutes, int seconds) const {
    if (hours < 0 || hours > 23) {
        cout << "Ошибка: от 0 до 23!" << endl;
        return false;
    }
    if (minutes < 0 || minutes > 59) {
        cout << "Ошибка: от 0 до 59!" << endl;
        return false;
    }
    if (seconds < 0 || seconds > 59) {
        cout << "Ошибка: от 0 до 59!" << endl;
        return false;
    }
    return true;
}

Time::Time(int sec) {
    if (isValidSec(sec)) {
        sec_ = sec;
    } else {
        cout << "Ошибка: количество секунд должно быть от 0 до 86399!" << endl;
        sec_ = 0;
    }
}

Time::Time(int hours, int minutes, int seconds) {
    if (isValidTime(hours, minutes, seconds)) {
        sec_ = hours * 3600 + minutes * 60 + seconds;
    } else {
        cout << "Установлено время по умолчанию: 00:00:00" << endl;
        sec_ = 0;
    }
}

void Time::setSec(int sec) {
    if (isValidSec(sec)) {
        sec_ = sec;
    } else {
        cout << "Ошибка: количество секунд должно быть от 0 до 86399!" << endl;
    }
}

int Time::getSec() const {
    return sec_;
}

void Time::print() const {
    cout << getTimeString() << endl;
}

string Time::getTimeString() const {
    string res = "";
    int hours = sec_ / 3600;
    int minutes = (sec_ % 3600) / 60;
    int second = sec_ % 60;
    
    res += char('0' + hours / 10);
    res += char('0' + hours % 10);
    res += ":";
    res += char('0' + minutes / 10);
    res += char('0' + minutes % 10);
    res += ":";
    res += char('0' + second / 10);
    res += char('0' + second % 10);
    
    return res;
}
