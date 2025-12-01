#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;

// Метод для заполнения бинарного файла случайными данными
void fillFileWithRandomData(const string& filename, int count) {
    ofstream file(filename, ios::binary);
    
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для записи!" << endl;
        return;
    }
    
    srand(time(nullptr)); // Инициализация генератора случайных чисел
    
    for (int i = 0; i < count; i++) {
        int randomNumber = rand() % 1000; // Генерируем числа от 0 до 999
        file.write(reinterpret_cast<const char*>(&randomNumber), sizeof(int));
    }
    
    file.close();
    cout << "Файл успешно заполнен " << count << " случайными числами." << endl;
}

// Функция для нахождения разности максимального и минимального элементов
int findDifference(const string& filename) {
    ifstream file(filename, ios::binary);
    
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для чтения!" << endl;
        return -1;
    }
    
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int number;
    
    // Читаем числа из файла и находим min и max
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number < minValue) {
            minValue = number;
        }
        if (number > maxValue) {
            maxValue = number;
        }
    }
    
    file.close();
    
    if (minValue == INT_MAX || maxValue == INT_MIN) {
        cerr << "Ошибка: файл пуст!" << endl;
        return -1;
    }
    
    cout << "Минимальный элемент: " << minValue << endl;
    cout << "Максимальный элемент: " << maxValue << endl;
    
    return maxValue - minValue;
}

int main() {
    const string filename = "data.bin";
    const int dataCount = 20; // Количество случайных чисел для генерации
    
    // Заполняем файл случайными данными
    fillFileWithRandomData(filename, dataCount);
    
    // Находим разность максимального и минимального элементов
    int difference = findDifference(filename);
    
    if (difference != -1) {
        cout << "Разность максимального и минимального элементов: " << difference << endl;
    }
    
    return 0;
}


