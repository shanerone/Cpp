#include "za2.h"

int main() {
    int n, count;

    cout << "Enter size matrix (n x n): ";
    if (!(cin >> n)) {
        cout << "Invalid input\n";
        return 1;
    }

    cout << "Enter count numbers in file: ";
    if (!(cin >> count)) {
        cout << "Invalid input\n";
        return 1;
    }

    string filename = "za2.bin";

    fill_random(filename, count);
    matrixFromFile(filename, n);

    return 0;
}
