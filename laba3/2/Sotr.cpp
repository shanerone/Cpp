#include "Sotr.h"
#include "Office.h"
#include <iostream>

using namespace std;

Sotrudnik::Sotrudnik(string name) {
    name_ = name;
    office = nullptr;
}

void Sotrudnik::setName(string name) {
    name_ = name;
}

string Sotrudnik::getName() const {
    return name_;
}

void Sotrudnik::setOffice(Office* off) {
    office = off;
}

Office* Sotrudnik::getOffice() const {
    return office;
}

void Sotrudnik::print() const {
    cout << ToString() << endl;
}

string Sotrudnik::ToString() const {
    if (office == nullptr) {
        return name_ + " работает без отдела";
    }
    Sotrudnik* boss = office->getBoss(); //-> разыменовыввние вместо (* ).четтам
    
    if (boss == this) { // на самого себя типо
            return name_ + " начальник отдела " + office->getName();
        }
        
        if (boss == nullptr) {
            return name_ + " работает в отделе " + office->getName() + ", начальник не назначен";
        }
        return name_ + " работает в отделе " + office->getName() + ", начальник которого " + boss->getName();
}
