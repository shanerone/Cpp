#include <iostream>
using namespace std;

int * deleteNegative (int arr[], int size) {
    for (int i = 0; i < size; i++) {

    }
}

int main() {
    int size;
    cout << "Enter num: ";
    if (!(cin >> size)) {
        cerr << "incorrect" << endl;
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
}
