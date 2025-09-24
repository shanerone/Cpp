#include <iostream>
using namespace std;

int charToNum (char x) {
    return x - '0';
}

int main() {
    char x;
    cout << "Enter num: ";
    cin >> x;
    cout << charToNum(x) << endl;
    return 0;
}
