#include <iostream>
using namespace std;

int max3 (int x, int y, int z) {
    int max;
    if (x > y){
        max = x;
    }
    else{
        max = y;
    }
    if (max > z){
        return max;
    }
    else{
        return z;
    }
}

int main() {
    int x, y ,z;
    cout << "Enter x, y ,z: ";
    if (!(cin >> x >> y >> z)) {
        cout << "incorrect" << endl;
        return 1;
    }
    cout << max3(x, y ,z) << endl;
}
