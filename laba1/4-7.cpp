#include <iostream>
using namespace std;

int * reverseBack (int arr[], int size) {
    int* newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[size - i -1];
    }
    return newArr;
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

    int* revers = reverseBack(arr, size);

    cout << "Новый массивчик: ";
    for (int i = 0; i < size; i++){
        cout << revers[i] << " ";
    }
    cout << endl;
    return 0;
}
