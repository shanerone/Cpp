#include <iostream>
using namespace std;

string chet(int x) {
    for (int i = 0; i <= x; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    return " ";
}

int main() {
    int x;
    cout << "Enter number: ";
    if (!(cin >> x)) {
        cerr << "incorrect" << endl;
        return 1;
    }
    chet(x);
    return 0;
}
