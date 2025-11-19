#include <iostream>
#include <vector>

int main() {
    std::vector<int> V;
    int size;
    std::cout << "enter size: ";
    if (!(std::cin >> size) or (size % 2 == 0) or (size < 5)) {
        std::cout << "incorrect" << std::endl;
        return 1;
    }
    std::cout << "enter elements: ";
    for (int i = 0; i < size; i++) {
        int elem;
        if (!(std::cin >> elem)) {
            std::cout << "incorrect" << std::endl;
            return 1;
        }
        V.push_back(elem);
    }

    std::cout << "original" << std::endl;
    for (int i = 0; i < V.size(); i++) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;
    int middle = V.size() / 2;
    V.erase(V.begin() + middle - 1, V.begin() + middle + 2);

    std::cout << "after removing three middle elements" << std::endl;
    for (int i = 0; i < V.size(); i++) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;
}
