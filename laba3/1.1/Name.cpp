#include "Name.h"

Name::Name(string familiya, string name, string otchestvo):
    familiya_(familiya), name_(name), otchestvo_(otchestvo){
}

string Name::toString() const {
    string res = "";
    if (!familiya_.empty()) {
        res += familiya_;
    }

    if (!name_.empty()) {
        if (res != "") res += " ";
        res += name_;
    }

    if (!otchestvo_.empty()) {
        if (res != "") res += " ";
        res += otchestvo_;
    }

    return res;
}
