#include <iostream>
#include <list>
using namespace std;

int main() {
    int size;
    cout << "Enter size: ";
    if (!(cin >> size) and size <= 0) {
        cout << "incorrect" << endl;
        return 1;
    }
    list<int> L;
        cout << "Enter elements: ";
        for (int i = 0; i < size; ++i) {
            int val;
            if (!(cin >> val)) {
                cout << "Incorrect input" << endl;
                return 1;
            }
            L.push_back(val);
        }
    cout << "defolt arr: ";
    for (auto i = L.begin(); i != L.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    cout << "revers arr: " ;
    for (auto i = L.rbegin(); i != L.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
