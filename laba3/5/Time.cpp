#include "Time.h"
#include <iostream>

using namespace std;

bool Time::isValidSec(int sec) const {
    return sec >= 0 && sec < 86400;
}

bool Time::isValidTime(int hours, int minutes, int seconds) const {
    if (hours < 0 || hours > 23) {
        cout << "Ошибка: часы должны быть от 0 до 23!" << endl;
        return false;
    }
    if (minutes < 0 || minutes > 59) {
        cout << "Ошибка: минуты должны быть от 0 до 59!" << endl;
        return false;
    }
    if (seconds < 0 || seconds > 59) {
        cout << "Ошибка: секунды должны быть от 0 до 59!" << endl;
        return false;
    }
    return true;
}

Time::Time(int sec) {
    if (sec < 0) {
        cout << "Ошибка!" << endl;
        sec_ = 0;
    } else if (sec >= 86400) {
        cout << "Внимание: количество секунд больше суток (86400)!" << endl;
        sec_ = sec % 86400;
    } else {
        sec_ = sec;
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
    if (sec < 0) {
        cout << "Ошибка!" << endl;
    } else if (sec >= 86400) {
        cout << "количество секунд больше суток (86400)!" << endl;
        sec_ = sec % 86400;
    } else {
        sec_ = sec;
    }
}

int Time::getSec() const {
    return sec_;
}

int Time::getHours() const {
    return sec_ / 3600;
}

int Time::getMinutes() const {
    return (sec_ % 3600) / 60;
}

int Time::getSeconds() const {
    return sec_ % 60;
}

void Time::print() const {
    cout << getTimeString() << endl;
}

string Time::getTimeString() const {
    string res = "";
    int hours = getHours();
    int minutes = getMinutes();
    int second = getSeconds();

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
