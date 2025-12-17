#include "za3.h"

int main() {
    int k;
    cout << "Введите допустимое отклонение цены (k) в рублях: ";
    if (!(cin >> k)) {
        cout << "Invalid input\n";
        return 1;
    }

    string filename = "za3.bin";

    fillFileWithToys(filename);
    findExpensiveToys(filename, k);

    return 0;
}
