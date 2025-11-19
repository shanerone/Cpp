#include "Time.h"
#include <iostream>

int main() {
    int sec;
    cout << "Enter sec: ";
    if (!(cin >> sec)) {
        cout << "incorrect" << endl;
        return 1;
    }
   
    if (sec < 0) {
        cout << "Enter positive sec! ";
        return 1;
    }
    
    Time secTime(sec);
    
    secTime.print();
    
    return 0;
}