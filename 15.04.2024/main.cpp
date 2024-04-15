#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "list.hpp"

using namespace std;

const string SOURCE_FILENAME = "./source.txt";

int main() {
    ifstream file(SOURCE_FILENAME);
    string line;
    MyList list;
    while (!file.eof()) {
        getline(file, line);
        stringstream ss(line);
        double temp;
        while (ss >> temp) {
            list.push(temp);
        }
    }
    list.OutputDList();
    file.close();
    return 0;
}