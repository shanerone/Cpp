#include "Time.h"
#include <iostream>

using namespace std;

int main() {
    cout << "По ТЗ" << endl;
    cout << endl;
    
    cout << "Задача 1: 34056 секунд" << endl;
    Time t1(34056);
    cout << "Часы: " << t1.getHours() << endl;
    cout << "Полное время: ";
    t1.print();
    cout << endl;
    
    cout << "Задача 2: 4532 секунды" << endl;
    Time t2(4532);
    cout << "Минуты в текущем часе: " << t2.getMinutes() << endl;
    cout << "Полное время: ";
    t2.print();
    cout << endl;
    
    cout << "Задача 3: 123 секунды" << endl;
    Time t3(123);
    cout << "Секунды в текущей минуте: " << t3.getSeconds() << endl;
    cout << "Полное время: ";
    t3.print();
    cout << endl;
    
    cout << "Обычный ввод" << endl;
    cout << endl;
    
    int sec;
    cout << "Введи количество секунд: ";
    
    if (!(cin >> sec)) {
        cout << "Ошибка ввода!" << endl;
        return 1;
    }
    
    Time t(sec);
    
    cout << "Часы: " << t.getHours() << endl;
    cout << "Минуты: " << t.getMinutes() << endl;
    cout << "Секунды: " << t.getSeconds() << endl;
    cout << "Полное время: ";
    t.print();
    
    return 0;
}
