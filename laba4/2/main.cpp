#include "Time.h"

int main() {
    Time t1(14, 30);
    Time t2(9, 45);
    Time t3(0, 0);
    
    cout << "Исходные времена:\n";
    cout << "t1 = " << t1.toString() << "\n";
    cout << "t2 = " << t2.toString() << "\n";
    cout << "t3 = " << t3.toString() << "\n\n";
    
    cout << "Префиксный ++:\n";
    cout << "t1 до: " << t1.toString() << "\n";
    ++t1;
    cout << "t1 после ++t1: " << t1.toString() << "\n\n";
    
    cout << "Постфиксный ++:\n";
    cout << "t2 до: " << t2.toString() << "\n";
    Time temp = t2++;
    cout << "t2 после t2++: " << t2.toString() << "\n";
    cout << "Возвращенное значение (t2++): " << temp.toString() << "\n\n";
    
    cout << "Префиксный --:\n";
    cout << "t1 до: " << t1.toString() << "\n";
    --t1;
    cout << "t1 после --t1: " << t1.toString() << "\n\n";
    
    cout << "Постфиксный --:\n";
    cout << "t2 до: " << t2.toString() << "\n";
    Time temp2 = t2--;
    cout << "t2 после t2--: " << t2.toString() << "\n";
    cout << "Возвращенное значение (t2--): " << temp2.toString() << "\n\n";
    
    cout << "Переход в новый день:\n";
    Time t4(23, 59);
    cout << "t4 = " << t4.toString() << "\n";
    ++t4;
    cout << "После ++: " << t4.toString() << "\n";
    
    Time t5(0, 0);
    cout << "t5 = " << t5.toString() << "\n";
    --t5;
    cout << "После --: " << t5.toString() << "\n";
    
    
    Time t6(10, 15);
    Time t7(0, 0);
    
    cout << "приведение к int (количество минут):\n";
    cout << "t6 = " << t6.toString() << " = " << (int)t6 << " минут\n";
    cout << "t7 = " << t7.toString() << " = " << (int)t7 << " минут\n\n";
    
    cout << "Явное приведение к bool:\n";
    if (t6) {
        cout << "t6 = " << t6.toString() << " -> true (не нулевое время)\n";
    }
    if (!(bool)t7) {
        cout << "t7 = " << t7.toString() << " -> false (нулевое время)\n";
    }
    cout << "\n";
    
    cout << "Бинарные операции\n\n";
    
    Time t8(15, 30);
    Time t9(10, 45);
    Time t10(15, 30);
    
    cout << "Времена для сравнения:\n";
    cout << "t8 = " << t8.toString() << "\n";
    cout << "t9 = " << t9.toString() << "\n";
    cout << "t10 = " << t10.toString() << "\n\n";
    
    cout << "Оператор <:\n";
    if (t9 < t8) {
        cout << t9.toString() << " < " << t8.toString() << " -> true\n";
    } else {
        cout << t9.toString() << " < " << t8.toString() << " -> false\n";
    }
    cout << "\n";
    
    cout << "Оператор >:\n";
    if (t8 > t9) {
        cout << t8.toString() << " > " << t9.toString() << " -> true\n";
    } else {
        cout << t8.toString() << " > " << t9.toString() << " -> false\n";
    }
    cout << "\n";
    
    short int h, m;
    cout << "Введите часы (0-23): ";
    if (!(cin >> h)){
        cout << "Invalid hours\n";
        return 1;
    }
    cout << "Введите минуты (0-59): ";
    if (!(cin >> m)){
        cout << "Invalid minutes\n";
        return 1;
    }
    
    Time userTime(h, m);
    cout << "Ваше время: " << userTime.toString() << "\n";
    cout << "В минутах: " << (int)userTime << "\n";
    cout << "Не нулевое: " << ((bool)userTime ? "да" : "нет") << "\n";
    
    cout << "\nПосле ++: " << (++userTime).toString() << "\n";
    cout << "После --: " << (--userTime).toString() << "\n";
    
    return 0;
}
