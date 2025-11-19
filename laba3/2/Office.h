#pragma once
#include <string>

using namespace std;

class Sotrudnik;

class Office{
private:
    string name_;
    Sotrudnik* boss;
public:
    Office(string name);
    
    void setName(string name);
    string getName() const;
    
    void setBoss(Sotrudnik* b);
    Sotrudnik* getBoss() const;
    
    void print() const;
};