#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int GenRandNum() {
    return rand() % 100;
}

int FindMaxandCount(const string& filename, int& count) {
    ifstream in(filename);
    if (!in.is_open()){
        cout << "File dont open" << endl;
        return 1;
    }
    int maxVal = 0;
    count = 0;
    int num;
    while (in >> num) {
        if (num > maxVal) {
            maxVal = num;
            count = 1;
        } else if (num == maxVal) {
            count++;
        }
    }
    in.close();
    return maxVal;
}

int main() {
    srand(time(0));
    ofstream out("zad4.txt");
    if (out.is_open()) {
        for (int i = 0; i < 25; i++) {
            out << GenRandNum() << " ";
        }
    }
    out.close();
    int count = 0;
    int maxEl = FindMaxandCount("zad4.txt", count);
    cout << "Max elem: " << maxEl << endl;
    cout << "Amount: " << count << endl;
    return 0;
}