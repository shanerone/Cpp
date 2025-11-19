#include <iostream>
using namespace std;

int numLen (long x) {
    int len = 0;
    while (x!= 0) {
        x /= 10;
        len ++;
    }
    return len;
}

int main() {
    long x;
    cout << "Enter num: ";
    if (!(cin >> x)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << numLen(x) << endl;
}
