#include "Sotr.h"
#include "Office.h"
#include <iostream>

using namespace std;

int main() {
    Office officeIT("IT");
    Sotrudnik petrov("Петров");
    Sotrudnik kozlov("Козлов");
    Sotrudnik sidorov("Сидоров");
    
    petrov.setOffice(&officeIT);
    kozlov.setOffice(&officeIT);
    sidorov.setOffice(&officeIT);
    
    officeIT.setBoss(&kozlov);
    
    cout << "Информация о сотрудниках" << endl;
    cout << endl;
    
    petrov.print();
    kozlov.print();
    sidorov.print();
    
    cout << endl;
    cout << "Информация об отделе" << endl;
    officeIT.print();
    
    cout << endl;
    cout << "Все сотрудники отдела IT" << endl;
    officeIT.printEmployees();
    
    cout << endl;
    cout << "Поиск коллег" << endl;
    string searchName;
    cout << "Введите фамилию сотрудника: ";
    cin >> searchName;
    
    Sotrudnik* foundEmployee = nullptr;
    if (searchName == petrov.getName()) {
        foundEmployee = &petrov;
    } else if (searchName == kozlov.getName()) {
        foundEmployee = &kozlov;
    } else if (searchName == sidorov.getName()) {
        foundEmployee = &sidorov;
    }
    
    if (foundEmployee == nullptr) {
        cout << "Сотрудник " << searchName << " не найден!" << endl;
    } else {
        cout << endl;
        cout << "Коллеги " << searchName << ":" << endl;
        vector<Sotrudnik*> colleagues = foundEmployee->getDepartmentEmployees();
        
       
        int count = 1;
        for (int i = 0; i < colleagues.size(); i++) {
            if (colleagues[i] != foundEmployee) {  
                cout << " " << count << ". " << colleagues[i]->getName() << endl;
                count++;
            }
        }
        
        if (count == 1) {
            cout << " Нет коллег в отделе" << endl;
        }
    }
    
    return 0;
}
