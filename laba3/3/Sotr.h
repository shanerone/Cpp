#pragma once

#include <string>
#include <vector>

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
    
    void setOffice(Office* off);
    Office* getOffice() const;
    
    vector<Sotrudnik*> getDepartmentEmployees() const;
    
    void print() const;
    string toString() const;
};
