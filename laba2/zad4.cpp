#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double A, D;
    int N;

    cout << "input A: ";
    if (!(cin >> A)) {
        cout << "incorrect input" << endl;
        return 1;
    }
    
    cout << "input D: ";
    if (!(cin >> D)) {
        cout << "incorrect input" << endl;
        return 1;
    }
    
    cout << "input N: ";
    if (!(cin >> N) || N <= 0) {
        cout << "incorrect input (N must be positive)" << endl;
        return 1;
    }

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
