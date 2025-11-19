#include <iostream>
using namespace std;
//параметр-ссылка, который позволяет функции
// напрямую менять переменную, переданную в неё снаружи.
int* findAll(int arr[], int size, int x, int &resultSize) {
    int ind = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) ind++;
    }
    resultSize = ind;
    int* newArr = new int[ind];
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            newArr[pos++] = i;
        }
    }
    return newArr;
}

int main() {
    int size, x;
    cout << "Enter size: ";
    if (!(cin >> size)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << "Enter x: ";
    if (!(cin >> x)) {
        cerr << "incorrect" << endl;
        return 1;
    }
    int* arr = new int[size];
    cout << "Введите содержимое массива: ";
    for (int i = 0; i < size; i++) {
        if (!(cin >> arr[i])) {
            cout << "Ошибка ввода" << endl;
            delete[] arr;
            return 1;
        }
    }

    int resultSize;
    int* res = findAll(arr, size, x, resultSize);
    for (int i = 0; i < resultSize; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
