#include <iostream>
#include "za1.h"

using namespace std;

int main() {
    int n;
    cout << "Введите количество сладкоежек: ";
    cin >> n;
    cin.ignore();
    
    UniqueList sweetLovers[100];
    
    for (int i = 0; i < n; i++) {
        cout << "\nСладкоежка " << (i + 1) << ":\n";
        cout << "Введите названия шоколадов (введите 'конец' для завершения):\n";
        
        string chocolate;
        while (true) {
            cout << "Название: ";
            getline(cin, chocolate);
            
            if (chocolate == "конец") break;
            
            sweetLovers[i].Add(chocolate);
        }
    }
    
    UniqueList allChocolates;
    for (int i = 0; i < n; i++) {
        allChocolates = allChocolates.Union(sweetLovers[i]);
    }
    
    cout << "\nLike all (" << n << " сладкоежкам):\n";
    UniqueList allLikeChocolate = sweetLovers[0];
    for (int i = 1; i < n; i++) {
        allLikeChocolate = allLikeChocolate.Intersect(sweetLovers[i]);
    }
    
    if (allLikeChocolate.GetSize() == 0) {
        cout << "No this chocolate\n";
    } else {
        allLikeChocolate.Print();
        cout << "\n";
    }
    
    cout << "\nLike some:\n";
    UniqueList someChocolate;
    for (int i = 0; i < allChocolates.GetSize(); i++) {
        string chocolate = allChocolates.Get(i);
        
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (sweetLovers[j].Contains(chocolate)) {
                count++;
            }
        }
        
        if (count > 0 && count < n) {
            someChocolate.Add(chocolate);
        }
    }
    
    if (someChocolate.GetSize() == 0) {
        cout << "No this chocolate\n";
    } else {
        someChocolate.Print();
        cout << "\n";
    }
    
    cout << "\nNo like:\n";
    UniqueList noneChocolate;
    for (int i = 0; i < allChocolates.GetSize(); i++) {
        string chocolate = allChocolates.Get(i);
        
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (sweetLovers[j].Contains(chocolate)) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            noneChocolate.Add(chocolate);
        }
    }
    
    if (noneChocolate.GetSize() == 0) {
        cout << "No this chocolate\n";
    } else {
        noneChocolate.Print();
        cout << "\n";
    }
    
    return 0;
}
