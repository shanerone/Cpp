#include "5.h"

int GenRandNum() {
    return rand() % 100;
}

int CountEven(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "File dont open" << endl;
        return 1;  // можно считать кодом ошибки
    }

    int count = 0;
    int num;

    while (in >> num) {
        if (num % 2 == 0) {
            count++;
        }
    }

    in.close();
    return count;
}
