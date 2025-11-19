#include <iostream>
#include <list>
<<<<<<< HEAD
#include <algorithm>
#include <iterator>
=======
#include <iterator>
#include <algorithm>
>>>>>>> bb744b3 (laba3-4)

using namespace std;

int main() {
    list<int> L;
<<<<<<< HEAD
    int size;
    int K;

    cout << "enter K (0 < K < 5): ";
    if (!(cin >> K) || K <= 0 || K >= 5) {
=======
    int size, K;

    cout << "enter K (0 < K < 5): ";
    cin >> K;
    if (K <= 0 || K >= 5) {
>>>>>>> bb744b3 (laba3-4)
        cout << "incorrect input" << endl;
        return 1;
    }

    cout << "enter size (minimum 10): ";
<<<<<<< HEAD
    if (!(cin >> size) || size < 10) {
        cout << "incorrect input " << endl;
=======
    cin >> size;
    if (size < 10) {
        cout << "incorrect input" << endl;
>>>>>>> bb744b3 (laba3-4)
        return 1;
    }

    cout << "enter elements: ";
<<<<<<< HEAD
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
=======
    for (int i = 0; i < size; ++i) {
        int x; cin >> x;
        L.push_back(x);
    }

    cout << "original list: ";
    for (int x : L) cout << x << " ";
>>>>>>> bb744b3 (laba3-4)
    cout << endl;

    auto first5Begin = L.begin();
    auto first5End = L.begin();
    advance(first5End, 5);

    auto last5Begin = L.end();
    advance(last5Begin, -5);
    auto last5End = L.end();

<<<<<<< HEAD
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
=======
    list<int> tempLast5;
    auto middleLeft = last5Begin;
    advance(middleLeft, K);
    rotate_copy(last5Begin, middleLeft, last5End, back_inserter(tempLast5));

    L.insert(L.begin(), tempLast5.begin(), tempLast5.end());

    list<int> tempFirst5;
    auto middleRight = first5Begin;
    advance(middleRight, 5 - K);
    rotate_copy(first5Begin, middleRight, first5End, back_inserter(tempFirst5));

    for (int val : tempFirst5) {
        L.push_back(val);
    }

    cout << "modified list: ";
    for (int x : L) cout << x << " ";
>>>>>>> bb744b3 (laba3-4)
    cout << endl;

    return 0;
}
