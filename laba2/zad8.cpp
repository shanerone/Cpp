#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <iterator>
#include <numeric>
using namespace std;

struct PairTransform {
    string operator()(const string &right, const string &left) {
        return (!left.empty() && !right.empty()) ?
                   string{left.front(), right.back()} : string();
    }
};

int main() {
    cout << "imput kol-vo word: ";
    int n;
    cin >> n;

    list<std::string> L;
    cout << "input words:" << endl;
    for (int i = 0; i < n; ++i) {
       string word;
       cin >> word;
       L.push_back(word);
    }

    deque<string> D;

    adjacent_difference(L.begin(), L.end(), inserter(D, D.begin()), PairTransform());

    if (!D.empty()) {
        D.erase(D.begin());
    }

    cout << "result:"<< endl;
    for (const auto &s : D) {
        std::cout << s << std::endl;
    }

    return 0;
}
