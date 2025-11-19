#include <iostream>
using namespace std;

int maxAbs (int arr[], int size) {
    int max = 0;
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) > max) {
            max = abs(arr[i]);
        }
    }
    return max;
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
    cout << maxAbs(arr, size)<< endl;
    return 0;
}
