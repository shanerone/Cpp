#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeLinesToFile(const string& filename);

void searchAndWrite(const string& inputFilename, const string& outputFilename, const string& searchWord);

