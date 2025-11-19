#include <iostream>
using namespace std;

bool isEqual(int a, int b, int c){
    return a == b and b == c;
}

int main() {
    int a, b, c;
    cout << "Enter a, b, c: ";
    if (!(cin >> a >> b >> c)) {
        cout << "incorret" << endl;
        return 1;
    }
    if (isEqual(a, b, c)) {
        cout << "True:" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
