<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> V;
    int size;

    cout << "enter size: ";
    if (!(cin >> size) or (size % 2 != 0)) {
        cout << "incorrect" << endl;
        return 1;
    }

    cout << "enter elem: ";
    for (int i = 0; i < size; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect";
            return 1;
        }
        V.push_back(elem);
    }

    cout << "original vector: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    int half_size = size / 2;

    V.insert(V.end(), half_size, 0);

    partial_sort_copy(V.begin(), V.begin() + size,
                              V.begin() + size, V.end());

    cout << "result: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << std::endl;

    return 0;
}
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> V;
    int size;

    cout << "enter size: ";
    if (!(cin >> size) or (size % 2 != 0)) {
        cout << "incorrect" << endl;
        return 1;
    }

    cout << "enter elem: ";
    for (int i = 0; i < size; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect";
            return 1;
        }
        V.push_back(elem);
    }

    cout << "original vector: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    int half_size = size / 2;

    V.insert(V.end(), half_size, 0);

    partial_sort_copy(V.begin(), V.begin() + size,
                              V.begin() + size, V.end());

    cout << "result: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << std::endl;

    return 0;
}
>>>>>>> bb744b3 (laba3-4)
