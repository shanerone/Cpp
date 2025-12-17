#include "za1.h"
#include <iostream>
using namespace std;

UniqueList::UniqueList() {
    size = 0;
}

void UniqueList::Add(string item) {
    if (!Contains(item)) {
        items[size] = item;
        size++;
    }
}

void UniqueList::Remove(string item) {
    for (int i = 0; i < size; i++) {
        if (items[i] == item) {
            for (int j = i; j < size - 1; j++) {
                items[j] = items[j + 1];
            }
            size--;
            return;
        }
    }
}

bool UniqueList::Contains(string item) {
    for (int i = 0; i < size; i++) {
        if (items[i] == item) {
            return true;
        }
    }
    return false;
}

UniqueList UniqueList::Union(UniqueList other) {
    UniqueList result = *this;
    
    for (int i = 0; i < other.size; i++) {
        result.Add(other.items[i]);
    }
    
    return result;
}

UniqueList UniqueList::Except(UniqueList other) {
    UniqueList result;
    
    for (int i = 0; i < size; i++) {
        if (!other.Contains(items[i])) {
            result.Add(items[i]);
        }
    }
    
    return result;
}

UniqueList UniqueList::Intersect(UniqueList other) {
    UniqueList result;
    
    for (int i = 0; i < size; i++) {
        if (other.Contains(items[i])) {
            result.Add(items[i]);
        }
    }
    
    return result;
}

int UniqueList::GetSize() {
    return size;
}

string UniqueList::Get(int index) {
    if (index >= 0 && index < size) {
        return items[index];
    }
    return "";
}

void UniqueList::Print() {
    for (int i = 0; i < size; i++) {
        cout << items[i];
        if (i < size - 1) cout << ", ";
    }
}
