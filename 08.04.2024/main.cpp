#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "list.hpp"
#include "vector.hpp"

#define DIMESION 3

using namespace std;

const string SOURCE_FILENAME = "./source.txt";

double getVectorLength(string& line) {
    stringstream ss(line);
    string temp;
    double result = 0;
    while (ss >> temp) {
        if (stringstream(temp) >> result)
            break;
    }
    cout << "Vector length: " << result << endl;
    line = "";
    return result;
}

int getVectorAndLabel(string line, double cordinateList[]) {
    stringstream ss(line);
    string temp;
    double cordinate = 0;
    int label = 0;
    bool isFirstNumber = true;
    int i = 0;
    while (ss >> temp) {
        if (stringstream(temp) >> cordinate) {
            if (isFirstNumber) {
                isFirstNumber = false;
                label = cordinate;
                continue;
            }
            cordinateList[i++] = cordinate;
        }
    }
    return label;
}

void skipLine(ifstream& file) {
    string line;
    getline(file, line);
}

int main() {
    ifstream file(SOURCE_FILENAME);
    string line;
    MyList list;
    int label;
    double cordinateList[DIMESION] = {0};
    getline(file, line);
    double vectorLength = getVectorLength(line);
    skipLine(file);
    while (!file.eof()) {
        getline(file, line);
        label = getVectorAndLabel(line, cordinateList);
        Vector* vector = new Vector(cordinateList[0], cordinateList[1], cordinateList[2]);
        if (vector->GetLength() <= vectorLength) {
            list.push_back(label, vector);
        }
    }
    list.OutputList();
    double maxDistance = 0;
    int listSize = list.GetSize();
    Node* node1 = list.GetHead();
    Node* node2 = node1->next;
    Node* maxNode1, *maxNode2;
    for (int i = 0; i < listSize - 1; i++) {
        for (int j = i + 1; j < listSize; j++) {
            double distance = node1->vector->GetDistance(node2->vector);
            if (distance > maxDistance) {
                maxDistance = distance;
                maxNode1 = node1;
                maxNode2 = node2;
            }
            node2 = node2->next;
        }
        node1 = node1->next;
        node2 = node1->next;
    }
    cout << "Max distance: " << maxDistance << endl;
    cout << "First vector: ";
    maxNode1->OutputNode();
    cout << "Second vector: ";
    maxNode2->OutputNode();
    file.close();
    return 0;
}

