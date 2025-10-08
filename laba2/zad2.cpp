#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    vector<int> V = {1, 2, 3, 4};
    deque<int> D = {5, 6, 7, 8};

    cout << "Orig;" << endl;
    cout << "V: ";
    for (int x : V) cout << x << " ";
    cout << endl;
    cout << "D: ";
    for (int x : D) cout << x << " ";
    cout << endl;

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
    cout << "D: ";
    for (int x : D) cout << x << " ";
    cout << endl;

    return 0;
}
