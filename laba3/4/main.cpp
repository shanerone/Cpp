#include "Time.h"
#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "Выбери способ создания (1 - по секундам, 2 - по часам/минутам/секундам): ";
    
    if (!(cin >> choice)) {
        cout << "Ошибка ввода!" << endl;
        return 1;
    }
    
    if (choice == 1) {
        int sec;
        cout << "Введи количество секунд: ";
        
        if (!(cin >> sec)) {
            cout << "Ошибка ввода!" << endl;
            return 1;
        }
        
        Time t(sec);
        cout << "Результат: ";
        t.print();
        
    } else if (choice == 2) {
        int h, m, s;
        
        cout << "Введи часы: ";
        if (!(cin >> h)) {
            cout << "Ошибка ввода!" << endl;
            return 1;
        }
        
        cout << "Введи минуты: ";
        if (!(cin >> m)) {
            cout << "Ошибка ввода!" << endl;
            return 1;
        }
        
        cout << "Введи секунды: ";
        if (!(cin >> s)) {
            cout << "Ошибка ввода!" << endl;
            return 1;
        }
        
        Time t(h, m, s);
        cout << "Результат: ";
        t.print();
        
    } else {
        cout << "Неправильный выбор!" << endl;
        return 1;
    }
    
    return 0;
}
