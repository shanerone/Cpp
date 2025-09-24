#include <iostream>
using namespace std;

bool is2Digits (int x){
    return x >= 10 and x <= 99;
}

int main() {
    int x;
    cout << "Enter a number: ";
    if (!(cin >> x)) {
        cout << "incorrect!" << endl;
        return 1;
    }
    if (is2Digits(x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
