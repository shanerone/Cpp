#include <iostream>
using namespace std;

bool is35 (int x) {

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
