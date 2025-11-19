#include "Office.h"
#include "Sotr.h"
#include <iostream>

using namespace std;

Office::Office(string name) {
    name_ = name;
    boss = nullptr;
}

void Office::setName(string name) {
    name_ = name;
}

string Office::getName() const {
    return name_;
}

void Office::setBoss(Sotrudnik* b) {
    boss = b;
}

Sotrudnik* Office::getBoss() const {
    return boss;
}

void Office::addEmployee(Sotrudnik* emp) {
    employees.push_back(emp);
}

vector<Sotrudnik*> Office::getEmployees() const {
    return employees;
}

void Office::print() const {
    cout << "Отдел: " << name_;
    if (boss != nullptr) {
        cout << ", начальник: " << boss->getName();
    } else {
        cout << ", начальник не назначен";
    }
    cout << endl;
}

void Office::printEmployees() const {
    cout << "Сотрудники отдела " << name_ << ":" << endl;
    
    if (employees.size() == 0) {
        cout << "  Нет сотрудников" << endl;
        return;
    }
    
    for (int i = 0; i < employees.size(); i++) {
        cout << "  " << (i + 1) << ". " << employees[i]->getName() << endl;
    }
}
