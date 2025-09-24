#include <iostream>
using namespace std;

bool isInRange (int a, int b, int num) {
    int l, r;
    if (a < b) {
        l = a;
        r = b;
    }
    else {
        l = b;
        r = a;
    }
    if (num >= l and num <= r)
        return true;
    else
        return false;
}

int main() {
    int a, b, num;
    cout << "Введите значения начала и конца: ";
    if (!(cin >> a >> b)) {
            cout << "Ошибка ввода" << endl;
            return 1;
        }
    cout<<"Введите значение для поиска: ";
    if (!(cin >> num)) {
            cout << "Ошибка ввода" << endl;
            return 1;
        }

    bool InRange = isInRange(a, b ,num);

    if (InRange)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    return 0;
}
