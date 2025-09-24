#include <iostream>
using namespace std;

bool is35 (int x) {
    if (x  % 3 == 0 || x % 5 ==0) {
        if (x % 3 == 0 and x % 5 == 0) {
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    int x;
    cout << "Enter number: ";
    if (!(cin >> x)) {
        cout << "incorrect" << endl;
        return 1;
    }
    if (is35(x)) {
        cout << "True" << endl;
    } else {
        cout << "false" << endl;
    }
}
