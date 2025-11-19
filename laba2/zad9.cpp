#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int size0;
    cout << "enter size: ";
    if (!(cin >> size0)) {
        cout << "incorrect" << endl;
        return 1;
    }

    vector<int> V0(size0);
    cout << "enter elem V0: ";
    for (int i = 0; i < size0; i++) {
        cin >> V0[i];
    }

    multiset<int> ms0(V0.begin(), V0.end());

    int N;
    cout << "enter amount N: ";
    if (!(cin >> N)) {
        cout << "icorrect" << endl;
        return 1;
    }

    int count = 0;

    for (int i = 1; i <= N; i++) {
        int sizeI;
        cout << "enter size V" << i << ": ";
        if (!(cin >> sizeI)) {
            cout << "incorrect" << endl;
            return 1;
        }

        vector<int> VI(sizeI);
        cout << "enter elem V" << i << ": ";
        for (int j = 0; j < sizeI; j++) {
            cin >> VI[j];
        }

        multiset<int> msI(VI.begin(), VI.end());

        if (includes(msI.begin(), msI.end(), ms0.begin(), ms0.end())) {
            count++;
            cout << "V" << i << " contains all elements V0" << endl;
        } else {
            cout << "V" << i << " dont contains all elements V0" << endl;
        }
    }

    cout << "\nThe number of vectors containing all elements V0: " << count << endl;

    return 0;
}
