#include "za2.h"

void fill_random(const string& filename, int count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for write\n";
        return;
    }

    srand(time(0));

    for (int i = 0; i < count; i++) {
        int number = rand() % 100;
        file.write((char*)&number, sizeof(int));
    }

    file.close();
}

void matrixFromFile(const string& filename, int n) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for read\n";
        return;
    }

    int numbers[1000];
    int count = 0;
    int number;

    while (file.read((char*)&number, sizeof(int)) && count < 1000) {
        numbers[count] = number;
        count++;
    }

    file.close();

    int matrix[100][100] = {0};

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (index < count) {
                matrix[i][j] = numbers[index++];
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    int maxVal = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
    }

    cout << "\nMax element: " << maxVal << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == maxVal) {
                matrix[i][j] = 0;
            }
        }
    }

    cout << "\nMatrix " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}
