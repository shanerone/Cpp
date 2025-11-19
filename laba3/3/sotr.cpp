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
    if (office != nullptr) {
        office->addEmployee(this);
    }
}

Office* Sotrudnik::getOffice() const {
    return office;
}

vector<Sotrudnik*> Sotrudnik::getDepartmentEmployees() const {
    if (office == nullptr) {
        return vector<Sotrudnik*>();
    }
    return office->getEmployees();
}

void Sotrudnik::print() const {
    cout << toString() << endl;
}

string Sotrudnik::toString() const {
    if (office == nullptr) {
        return name_ + " работает без отдела";
    }
    
    Sotrudnik* boss = office->getBoss();
    
    if (boss == this) {
        return name_ + " начальник отдела " + office->getName();
    }
    
    if (boss == nullptr) {
        return name_ + " работает в отделе " + office->getName() + ", начальник не назначен";
    }
    
    return name_ + " работает в отделе " + office->getName() + ", начальник которого " + boss->getName();
}
