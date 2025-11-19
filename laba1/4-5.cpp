#include <iostream>
using namespace std;

int* add(int arr[], int sizeArr, int ins[], int sizeIns, int pos) {
    int* newArr = new int[sizeArr + sizeIns];
    for (int i = 0; i < pos; ++i)
        newArr[i] = arr[i];
    for (int i = 0; i < sizeIns; ++i)
        newArr[pos + i] = ins[i];
    for (int i = pos; i < sizeArr; ++i)
        newArr[sizeIns + i] = arr[i];
    return newArr;
}


int main() {
    int sizeArr, sizeIns, pos;

    cout << "Введите размер исходного массива: ";
    if (!(cin >> sizeArr)) {
        cout << "incorrect" << endl;
        return 1;
    }
    int* arr = new int[sizeArr];
    cout << "Введите элементы исходного массива: ";
    for (int i = 0; i < sizeArr; i++) {
        cin >> arr[i];
    }

    cout << "Введите размер массива для вставки: ";
    if (!(cin >> sizeIns)) {
        cout << "incorrect" << endl;
        return 1;
    }
    int* ins = new int[sizeIns];
    cout << "Введите элементы массива для вставки: ";
    for (int i = 0; i < sizeIns; i++) {
        cin >> ins[i];
    }

    cout << "Введите позицию для вставки: ";
    if (!(cin >> pos)) {
        cout << "incorrect" << endl;
        return 1;
    }

    if (pos < 0 || pos > sizeArr) {
        cout << "Некорректная позиция вставки" << endl;
        return 1;
    }

    int* result = add(arr, sizeArr, ins, sizeIns, pos);

    cout << "Результат: ";
    for (int i = 0; i < sizeArr + sizeIns; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
