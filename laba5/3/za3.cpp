#include "za3.h"

void fillFileWithToys(const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for write\n";
        return;
    }

    Toy toys[] = {
        {"Кубики",      150, 2, 5},
        {"Машинка",     280, 3, 8},
        {"Кукла",       320, 4, 10},
        {"Мяч",         120, 1, 6},
        {"Конструктор", 500, 5, 12},
        {"Пазл",        250, 6, 14}
    };

    int count = sizeof(toys) / sizeof(toys[0]);

    for (int i = 0; i < count; i++) {
        file.write((char*)&toys[i], sizeof(Toy));
    }

    file.close();
}

void findExpensiveToys(const string& filename, int k) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Error opening file for read\n";
        return;
    }

    Toy toys[1000];
    int count = 0;
    Toy toy;

    while (file.read((char*)&toy, sizeof(Toy))) {
        toys[count] = toy;
        count++;
    }

    file.close();

    if (count == 0) {
        cout << "Файл пуст\n";
        return;
    }

    int maxPrice = toys[0].price;
    for (int i = 0; i < count; i++) {
        maxPrice = max(maxPrice, toys[i].price);
    }

    cout << "\nMax price: " << maxPrice << " руб.\n";
    cout << "Допустимое отклонение: " << k << " руб.\n";
    cout << "\nMax price toys:\n";

    for (int i = 0; i < count; i++) {
        if (toys[i].price >= maxPrice - k) {
            cout << "Name: " << toys[i].name << "\n";
            cout << "Price: " << toys[i].price << " rub.\n";
            cout << "Age: " << toys[i].minAge
                 << "-" << toys[i].maxAge << " years\n\n";
        }
    }
}
