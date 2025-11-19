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
    
    return 0;
}
