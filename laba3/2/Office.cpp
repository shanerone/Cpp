#include "Office.h"
#include "Sotr.h"
#include <iostream>

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

void Office::print() const {
    cout << "Отдел: " << name_;
    if (boss != nullptr) {
        cout << ", начальник: " << boss->getName();
    } else {
        cout << ", начальник не назначен";
    }
    cout << endl;
}