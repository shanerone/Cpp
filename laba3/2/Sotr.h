#pragma once 
#include <string>

using namespace std;

class Office;

class Sotrudnik {
private:
    string name_;
    Office* office;
    
public:
    Sotrudnik(string name);
    
    void setName(string name);
    string getName() const;
    
    void setOffice(Office* office);
    Office* getOffice() const;
    
    void print() const;
    string ToString() const;
};