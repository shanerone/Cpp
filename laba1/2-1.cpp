#include <iostream>
using namespace std;

int abs (int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

int main() {
    int x;
    cout << "Enter x: ";
    if (!(cin >> x)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << abs(x) << endl;
    return 0;
}
