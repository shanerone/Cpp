#include <iostream>
using namespace std;

string day (int x) {
    if (x == 1) {
        return "Monday";
    } else if (x == 2) {
        return "Tuesday";
    } else if (x == 3) {
        return "Wednesday";
    } else if (x == 4) {
        return "Thursday";
    } else if (x == 5) {
        return "Friday";
    } else if (x == 6) {
        return "Saturday";
    } else if (x == 7) {
        return "Sunday";
    } else {
        return "incorrect";
    }
}

int main() {
    int x;
    cout  << "Enter number: ";
    if (!(cin >> x)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << day(x) << endl;
}
