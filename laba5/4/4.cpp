#include "4.h"

int GenRandNum() {
    return rand() % 100;
}

int FindMaxandCount(const string& filename, int& count) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "File dont open" << endl;
        return 1;  // можно вернуть 1 как ошибку
    }

    int maxVal = 0;
    count = 0;
    int num;

    while (in >> num) {
        if (num > maxVal) {
            maxVal = num;
            count = 1;
        } else if (num == maxVal) {
            count++;
        }
    }

    in.close();
    return maxVal;
}
