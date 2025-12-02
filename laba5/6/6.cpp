#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string line;
    string search;

    cout << "Input line: ";

    ofstream in("input.txt");
    if (in.is_open()) {
        string inputLine;
        while (getline(cin, inputLine) && !inputLine.empty()) {
            in << inputLine << endl; 
        }
        in.close();
    }
    
    cout << "Input word to search: ";
    cin >> search;

    ifstream readfile("input.txt");
    ofstream out("output.txt");

    if(!readfile.is_open()) {
        cout << "Error open file" << endl;
        return 1;
    }

    string fileline;
    while (getline(readfile, fileline)) {
        if (fileline.find(search) != string::npos) {
            out << fileline << endl;
        }
    }

    readfile.close();
    out.close();

    return 0;
}