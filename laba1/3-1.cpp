#include <iostream>
using namespace std;

string listNum (int x) {
    for (int i = 0; i <= x; i++) {
        cout << i << " ";
    }
    cout << endl;
    return "";
}

int main() {
    int x;
    cout << "Enter num: ";
    if (!(cin >> x)) {
        cout << "incorrect" << endl;
        return 1;
    }
    listNum(x);
    return 0;
}
