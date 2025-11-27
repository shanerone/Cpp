#include "Time.h"

int main() {
    
    Time t1;
    cout << "Конструктор по умолчанию: " << t1.toString() << "\n\n";
    
    cout << "Конструктор с параметрами\n";
    short int h, m;
    
    cout << "Введите часы (0-23): ";
    cin >> h;
    cout << "Введите минуты (0-59): ";
    cin >> m;
    
    Time t2(h, m);
    cout << "Создано время: " << t2.toString() << "\n\n";
    
    cout << "Конструктор копирования\n";
    Time t3 = t2;
    cout << "Скопировано время: " << t3.toString() << "\n\n";
    
    cout << "Введите новые часы (0-23): ";
    cin >> h;
    t2.setHours(h);
    cout << "Введите новые минуты (0-59): ";
    cin >> m;
    t2.setMinutes(m);
    cout << "Обновленное время: " << t2.toString() << "\n\n";
    
    cout << "Вычитание времени\n";
    cout << "Введите часы для второго времени (0-23): ";
    cin >> h;
    cout << "Введите минуты (0-59): ";
    cin >> m;
    
    Time t4(h, m);
    cout << "Второе время: " << t4.toString() << "\n";
    
    Time result = t2.subtractTime(t4);
    cout << t2.toString() << " - " << t4.toString() << " = " << result.toString() << "\n\n";
    
    cout << "Переход в предыдущие сутки\n";
    Time morning(8, 30);
    Time evening(20, 45);
    Time diff = morning.subtractTime(evening);
    cout << morning.toString() << " - " << evening.toString() << " = " << diff.toString() << "\n";
    
    return 0;
}
