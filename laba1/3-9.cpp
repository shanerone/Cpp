#include <iostream>
using namespace std;

void rightTriangle(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            cout << ' ';
        }
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << endl;
    }
}

int main() {
    int x;
    cout << "Enter num: ";
    cin >> x;
    rightTriangle(x);
    return 0;
}
