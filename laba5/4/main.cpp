#include "4.h"

int main() {
    srand(time(0));

    ofstream out("zad4.txt");
    if (out.is_open()) {
        for (int i = 0; i < 25; i++) {
            out << GenRandNum() << endl;
        }
        out.close();
    } else {
        cout << "File dont open for write" << endl;
        return 1;
    }

    int count = 0;
    int maxEl = FindMaxandCount("zad4.txt", count);

    cout << "Max elem: " << maxEl << endl;
    cout << "Amount: " << count << endl;

    return 0;
}
