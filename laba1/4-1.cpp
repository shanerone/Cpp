#include <iostream>
using namespace std;
int findFirst (int arr[], int x, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
int main() {
    int size;
    cout << "Введите размер массива: ";
    if (!(cin >> size)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }

    int* arr = new int[size];

    cout << "Введите содержимое массива: ";
    for (int i = 0; i < size; i++) {
        if (!(cin >> arr[i])) {
            cout << "Ошибка ввода" << endl;
            return 1;
        }
    }
    int x;
    cout << "enter num: ";
    if (!(cin >> x)) {
        cout << "Ошибка ввода" << endl;
        return 1;
    }
    int index = findFirst(arr, x, size);
    cout << index << endl;
    return 0;
}
