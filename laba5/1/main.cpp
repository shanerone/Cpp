#include "za1.h"

int main() {
    string filename = "za1.bin";
    int elementsCount;
    
    cout << "Enter number of el: ";
    
    if (!(cin >> elementsCount)) {
        cout << "Invalid input";
        return 1;
    }
    
    fill_random(filename, elementsCount);
    find_raznost(filename);
    
    return 0;
}
