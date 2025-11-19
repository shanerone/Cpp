#include <iostream>
using namespace std;

string day (int x) {
    switch (x) {
            case 1: return "Monday";
            case 2: return "Tuesday";
            case 3: return "Wednesday";
            case 4: return "Thursday";
            case 5: return "Friday";
            case 6: return "Saturday";
            case 7: return "Sunday";
            default: return "incorrect";
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
