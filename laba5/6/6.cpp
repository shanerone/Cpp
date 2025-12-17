#include "6.h"

void writeLinesToFile(const string& filename) {
    ofstream in(filename);
    if (in.is_open()) {
        string inputLine;
        cout << "Input line: ";
        while (getline(cin, inputLine) && !inputLine.empty()) {
            in << inputLine << endl;
        }
        in.close();
    }
}

void searchAndWrite(const string& inputFilename, const string& outputFilename, const string& searchWord) {
    ifstream readfile(inputFilename);
    ofstream out(outputFilename);

    if (!readfile.is_open()) {
        cout << "Error open file" << endl;
        return;
    }

    string fileline;
    while (getline(readfile, fileline)) {
        if (fileline.find(searchWord) != string::npos) {
            out << fileline << endl;
        }
    }

    readfile.close();
    out.close();
}
