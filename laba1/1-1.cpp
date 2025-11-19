#include <iostream>
using namespace std;

double fraction (double x){
    int chel = int(x);
    double res = x - chel;
    return abs(res);
}

int main() {
    double x;
    cout << "Enter number: ";
    if (!(cin >> x)) {
        cout << "Incorrect!" << endl;
        return 1;
    }
    cout << fraction(x)<< endl;
    return 0;
}
