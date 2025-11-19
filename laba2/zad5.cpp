#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> V;
    int size;

    cout << "enter size V: ";
    if (!(cin >> size) || size <= 0 || size % 2 != 0) {
        cout << "incorrect input" << endl;
        return 1;
    }

    cout << "enter elements: ";
    for (int i = 0; i < size; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect input" << endl;
            return 1;
        }
        V.push_back(elem);
    }

    cout << "original vector: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    int mid = V.size() / 2;
    auto firstHalfBegin = V.begin();
    auto firstHalfEnd = V.begin() + mid;
    auto secondHalfBegin = V.begin() + mid;
    auto secondHalfEnd = V.end();

    auto lastFound = V.end();

    auto current = firstHalfBegin;
    while (current != firstHalfEnd) {
        auto found = find_first_of(current, firstHalfEnd, secondHalfBegin, secondHalfEnd);

        if (found != firstHalfEnd) {
            lastFound = found;
            current = found + 1;
        } else {
            break;
        }
    }

    if (lastFound != V.end()) {
        V.insert(lastFound, 0);
        cout << "element found, inserting 0" << endl;
    } else {
        cout << "no matching elements found, vector unchanged" << endl;
    }

    cout << "result vector: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
