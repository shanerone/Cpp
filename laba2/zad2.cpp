#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    vector<int> V = {1, 2, 3, 4};
    deque<int> D = {5, 6, 7, 8};

    // Добавляем в конец V первую половину D
    int halfD = D.size() / 2;
    V.insert(V.end(), D.begin(), D.begin() + halfD);

    // Добавляем в начало D вторую половину V, но в обратном порядке
    int halfV = V.size() / 2;
    vector<int> tmp(V.begin() + halfV, V.end());
    reverse(tmp.begin(), tmp.end());
    D.insert(D.begin(), tmp.begin(), tmp.end());

    // Выводим результат
    cout << "V: ";
    for (int x : V) cout << x << " ";
    cout << endl;
    cout << "D: ";
    for (int x : D) cout << x << " ";
    cout << endl;
    return 0;
}
