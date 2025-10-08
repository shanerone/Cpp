#include <iostream>
#include <deque>
#include <vector>
using namespace std;


int main() {
    std::vector<int> V = {1, 2, 3, 4};
    std::deque<int> D = {4, 5, 6, 7};

    std::cout << "Vector: ";
    for (int i : V) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Deque: ";
    for (int i : D) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}
