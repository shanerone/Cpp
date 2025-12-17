#pragma once

#include <string>
using namespace std;

class UniqueList {
private:
    string items[100];
    int size;
    
public:
    UniqueList();
    
    void Add(string item);
    void Remove(string item);
    bool Contains(string item);
    
    UniqueList Union(UniqueList other);
    UniqueList Except(UniqueList other);
    UniqueList Intersect(UniqueList other);
    
    int GetSize();
    string Get(int index);
    void Print();
};
