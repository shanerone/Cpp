#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Toy {
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

void fillFileWithToys(const string& filename) {
    ofstream file(filename, ios::binary);
    
    Toy toys[] = {
        {"Кубики", 150, 2, 5},
        {"Машинка", 280, 3, 8},
        {"Кукла", 320, 4, 10},
        {"Мяч", 120, 1, 6},
        {"Конструктор", 500, 5, 12},
        {"Пазл", 250, 6, 14}
    };
    
    int count = sizeof(toys) / sizeof(toys[0]);
    
    for (int i = 0; i < count; i++) {
        file.write((char*)&toys[i], sizeof(Toy));
    }
    
    file.close();
    cout << "Файл заполнен " << count << " игрушками\n";
}

void findExpensiveToys(const string& filename, int k) {
    ifstream file(filename, ios::binary);
    
    Toy toys[1000];
    int count = 0;
    Toy toy;
    
    while (file.read((char*)&toy, sizeof(Toy))) {
        toys[count] = toy;
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "Файл пуст!\n";
        return;
    }
    
    int maxPrice = toys[0].price;
    for (int i = 0; i < count; i++) {
        maxPrice = max(maxPrice, toys[i].price);
    }
    
    cout << "\nМаксимальная цена: " << maxPrice << " руб.\n";
    cout << "Допустимое отклонение: " << k << " руб.\n";
    cout << "\nДорогие игрушки:\n";
    cout << "═══════════════════════════════════════════════════\n";
    
    for (int i = 0; i < count; i++) {
        if (toys[i].price >= maxPrice - k) {
            cout << "Название: " << toys[i].name << "\n";
            cout << "Цена: " << toys[i].price << " руб.\n";
            cout << "Возраст: " << toys[i].minAge << "-" << toys[i].maxAge << " лет\n";
            cout << "───────────────────────────────────────────────────\n";
        }
    }
}

int main() {
    int k;
    cout << "Введите допустимое отклонение цены (k) в рублях: ";
    cin >> k;
    
    fillFileWithToys("za3.bin");
    findExpensiveToys("za3.bin", k);
    
    return 0;
}
