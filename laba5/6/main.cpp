#include "6.h"

int main() {
    writeLinesToFile("input.txt");

    string search;
    cout << "Input word to search: ";
    cin >> search;

    searchAndWrite("input.txt", "output.txt", search);

    return 0;
}
