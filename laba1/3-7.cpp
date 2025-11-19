#include <iostream>
using namespace std;

void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << '*';
        }
        cout << endl;
    }
}

int main () {
    int x;
    cout << "Введите x: " << endl;
    if (!(cin >> x)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    square(x);
    return 0;
}
