#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> V;
    deque<int> D;
<<<<<<< HEAD
    int sizeV;
    cout << "enter size V: ";
    if (!(cin >> sizeV)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << "enter elements V: ";
    for (int i = 0; i < sizeV; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect" << endl;
            return 1;
        }
        V.push_back(elem);
    }

    int sizeD;
    cout << "enter size D: ";
    if (!(cin >> sizeD)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << "enter elements D: ";
    for (int i = 0; i < sizeD; i++) {
        int elem;
        if (!(cin >> elem)) {
            cout << "incorrect" << endl;
            return 1;
        }
        D.push_back(elem);
    }
    vector<int> secondHalfV;
    for (int i = V.size() / 2; i < V.size(); i++) {
        secondHalfV.push_back(V[i]);
    }

    vector<int> reversedSecondHalf;
    for (int i = secondHalfV.size() - 1; i >= 0; i--) {
        reversedSecondHalf.push_back(secondHalfV[i]);
    }

    for (int i = 0; i < D.size() / 2; i++) {
        V.push_back(D[i]);
    }

    deque<int> newD;
    for (int x : reversedSecondHalf) {
        newD.push_back(x);
    }
    for (int x : D) {
        newD.push_back(x);
    }
    D = newD;

    cout << "Done:" << endl;
    cout << "V: ";
    for (int x : V) cout << x << " ";
    cout << endl;
=======
    int sizeV, sizeD;

    cout << "enter size V: ";
    cin >> sizeV;
    cout << "enter elements V: ";
    for (int i = 0; i < sizeV; i++) {
        int elem;
        cin >> elem;
        V.push_back(elem);
    }

    cout << "enter size D: ";
    cin >> sizeD;
    cout << "enter elements D: ";
    for (int i = 0; i < sizeD; i++) {
        int elem;
        cin >> elem;
        D.push_back(elem);
    }

    if (V.size() % 2 != 0 || D.size() % 2 != 0) {
        cout << "Error: sizes must be even" << endl;
        return 1;
    }

    vector<int> secondHalfV(V.begin() + V.size() / 2, V.end());
    vector<int> reversedSecondHalf(secondHalfV.rbegin(), secondHalfV.rend());
    D.insert(D.begin(), reversedSecondHalf.begin(), reversedSecondHalf.end());
    V.insert(V.end(), D.begin() + reversedSecondHalf.size(), D.begin() + reversedSecondHalf.size() + D.size() / 2 - 1);

    cout << "V: ";
    for (int x : V) cout << x << " ";
    cout << endl;

>>>>>>> bb744b3 (laba3-4)
    cout << "D: ";
    for (int x : D) cout << x << " ";
    cout << endl;

    return 0;
}
