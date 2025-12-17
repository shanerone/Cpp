#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Toy {
    char name[50];
    int price;
    int minAge;
    int maxAge;
};

void fillFileWithToys(const string& filename);

void findExpensiveToys(const string& filename, int k);
