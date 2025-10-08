#include <iostream>
#include <vector>

int main() {
    std::vector<int> V = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "original" << std::endl;
    for (int i = 0; i < V.size(); i++) {
        std::cout << V[i];
    }
    std::cout << std::endl;
    int middle = V.size() / 2;
    V.erase(V.begin() + middle - 1, V.begin() + middle + 2);

    std::cout << "after removing three middle elements" << std::endl;
    for (int i = 0; i < V.size(); i++) {
        std::cout << V[i];
    }
    std::cout << std::endl;
}
