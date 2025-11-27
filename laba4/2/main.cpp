#include "Time.h"

int main() {
    Time t1(14, 30);
    Time t2(9, 45);
    Time t3(0, 0);

    cout << "Исходные времена:\n";
    cout << "t1 = " << t1 << "\n";
    cout << "t2 = " << t2 << "\n";
    cout << "t3 = " << t3 << "\n\n";

    cout << "Префиксный ++:\n";
    cout << "t1 до: " << t1 << "\n";
    ++t1;
    cout << "t1 после ++t1: " << t1 << "\n\n";

    cout << "Постфиксный ++:\n";
    cout << "t2 до: " << t2 << "\n";
    Time temp = t2++;
    cout << "t2 после t2++: " << t2 << "\n";
    cout << "Возвращенное значение (t2++): " << temp << "\n\n";

    cout << "Префиксный --:\n";
    cout << "t1 до: " << t1 << "\n";
    --t1;
    cout << "t1 после --t1: " << t1 << "\n\n";

    cout << "Постфиксный --:\n";
    cout << "t2 до: " << t2 << "\n";
    Time temp2 = t2--;
    cout << "t2 после t2--: " << t2 << "\n";
    cout << "Возвращенное значение (t2--): " << temp2 << "\n\n";

    cout << "Переход в новый день:\n";
    Time t4(23, 59);
    cout << "t4 = " << t4 << "\n";
    ++t4;
    cout << "После ++: " << t4 << "\n";

    Time t5(0, 0);
    cout << "t5 = " << t5 << "\n";
    --t5;
    cout << "После --: " << t5 << "\n";


    Time t6(10, 15);
    Time t7(0, 0);

    cout << "приведение к int (количество минут):\n";
    cout << "t6 = " << t6 << " = " << (int)t6 << " минут\n";
    cout << "t7 = " << t7 << " = " << (int)t7 << " минут\n\n";

    cout << "Явное приведение к bool:\n";
    if (t6) {
        cout << "t6 = " << t6 << " -> true (не нулевое время)\n";
    }
    if (!(bool)t7) {
        cout << "t7 = " << t7 << " -> false (нулевое время)\n";
    }
    cout << "\n";

    cout << "Бинарные операции\n\n";

    Time t8(15, 30);
    Time t9(10, 45);
    Time t10(15, 30);

    cout << "Времена для сравнения:\n";
    cout << "t8 = " << t8 << "\n";
    cout << "t9 = " << t9 << "\n";
    cout << "t10 = " << t10 << "\n\n";

    cout << "Оператор <:\n";
    if (t9 < t8) {
        cout << t9 << " < " << t8 << " -> true\n";
    } else {
        cout << t9 << " < " << t8 << " -> false\n";
    }
    cout << "\n";

    cout << "Оператор >:\n";
    if (t8 > t9) {
        cout << t8 << " > " << t9 << " -> true\n";
    } else {
        cout << t8 << " > " << t9 << " -> false\n";
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
    cout << "Ваше время: " << userTime << "\n";
    cout << "В минутах: " << (int)userTime << "\n";
    cout << "Не нулевое: " << ((bool)userTime ? "да" : "нет") << "\n";

    cout << "\nПосле ++: " << (++userTime) << "\n";
    cout << "После --: " << (--userTime) << "\n";

    return 0;
}
