#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    list<int> L;
    int size;
    int K;

    cout << "enter K (0 < K < 5): ";
    if (!(cin >> K) || K <= 0 || K >= 5) {
        cout << "incorrect input" << endl;
        return 1;
    }

    cout << "enter size (minimum 10): ";
    if (!(cin >> size) || size < 10) {
        cout << "incorrect input " << endl;
        return 1;
    }

    cout << "enter elements: ";
    for (int i = 0; i < size; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect input" << endl;
            return 1;
        }
        L.push_back(elem);
    }

    cout << "original list: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    auto first5Begin = L.begin();
    auto first5End = L.begin();
    advance(first5End, 5);

    auto last5Begin = L.end();
    advance(last5Begin, -5);
    auto last5End = L.end();

    auto middleRight = first5Begin;
    advance(middleRight, 5 - K);

    rotate_copy(first5Begin, middleRight, first5End, back_inserter(L));

    auto middleLeft = last5Begin;
    advance(middleLeft, K);

    rotate_copy(last5Begin, middleLeft, last5End, front_inserter(L));

    cout << "result list: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
