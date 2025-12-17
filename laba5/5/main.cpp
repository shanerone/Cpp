#include "5.h"

int main() {
    srand(time(0));

    ofstream out("zad5.txt");
    if (out.is_open()) {
        for (int i = 0; i < 25; i++) {
            out << GenRandNum();
            if ((i + 1) % 5 == 0) {
                out << endl;
            } else {
                out << " ";
            }
        }
        out.close();
    } else {
        cout << "File dont open for write" << endl;
        return 1;
    }

    cout << "Amount: " << CountEven("zad5.txt") << endl;

    return 0;
}
