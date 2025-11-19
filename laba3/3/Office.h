#pragma once

#include <string>
#include <vector>

using namespace std;

class Sotrudnik;

class Office {
private:
    string name_;
    Sotrudnik* boss;
    vector<Sotrudnik*> employees; //список указателей

public:
    Office(string name);
    
    void setName(string name);
    string getName() const;
    
    void setBoss(Sotrudnik* b);
    Sotrudnik* getBoss() const;
    
    void addEmployee(Sotrudnik* emp);
    vector<Sotrudnik*> getEmployees() const;
    
    void print() const;
    void printEmployees() const;
};
