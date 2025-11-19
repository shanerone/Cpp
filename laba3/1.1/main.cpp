#include <iostream>
#include "Name.h"

int main() {
    string name, familiya, otchestvo;
    cout << "enter name: ";
    getline(cin, name);
    cout << "enter  familiya: ";
    getline(cin, familiya);
    cout << "enter otchestvo: ";
    getline(cin, otchestvo);

    Name person(familiya, name, otchestvo);
    cout<< person.toString() << endl;

    return 0;
}
