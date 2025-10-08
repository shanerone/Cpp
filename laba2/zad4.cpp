#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double A, D;
    int N;

    cout << "input A: ";
    cin >> A;
    cout << "input D: ";
    cin >> D;
    cout << "input N: ";
    cin >> N;

    vector<double> progression(N);

    double current = A;
    generate_n(progression.begin(), N, [&]() {
        double result = current;
        current += D;
        return result;
    });

    cout << "result: ";

    for (const double& element : progression) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
