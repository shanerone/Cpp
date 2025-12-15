#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void fill_random(const string& filename, int count) {
    ofstream file(filename, ios::binary);

    srand(time(0));

    for (int i = 0; i < count; i++) {
        int number = rand() % 100;
        file.write((char*)&number, sizeof(int)); //4 байта, char работает с байтами
    }

    file.close();
}

void find_raznost(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file) {
        cout << "Error opening file";
        return;
    }

    int number;
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int count = 0;

    while (file.read((char*)&number, sizeof(int))) {
        maxVal = max(maxVal, number);
        minVal = min(minVal, number);
        count++;
    }

    file.close();

    if (count == 0) {
        cout << "Файл пуст!\n";
        return;
    }

    int difference = maxVal - minVal;

    cout << "Max: " << maxVal << "\n";
    cout << "Min: " << minVal << "\n";
    cout << "Diff: " << difference << "\n";
}

int main() {
    string filename = "data.bin";
    int elementsCount;

    cout << "Enter number of el: ";
    cin >> elementsCount;

    fill_random(filename, elementsCount);
    find_raznost(filename);

    return 0;
}
