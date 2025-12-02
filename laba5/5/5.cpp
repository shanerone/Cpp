#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int GenRandNum() {
    return rand() % 100;
}

int CountEven(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "File dont open" << endl;
        return 1;
    }
    int count = 0;
    int num;

    while (in >> num) {
        if (num % 2 == 0) count++;
    }

    in.close();
    return count;
}

int main() {
    srand(time(0));
    ofstream out("zad5.txt");
    if (out.is_open()) {
        for (int i = 0; i < 25; i++) {
            out << GenRandNum();
            if ((i +1) % 5 == 0) {
                out << endl;
            } else {
                out << " ";
            }
        }
    }
    out.close();
    cout << "Amount:" << CountEven("zad5.txt") << endl;
    return 0;
}