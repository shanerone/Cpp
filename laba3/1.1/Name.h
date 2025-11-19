#pragma once
#include <string>
using namespace std;

class Name{
private:
    string familiya_;
    string name_;
    string otchestvo_;

    bool isValidName(string name) const;
    bool isValidFam(string familiya) const;
    bool isValidOtch(string otchestvo) const;

public:
    Name(string familiya = "", string name = "", string otchestvo = "");

    string toString() const;
};
