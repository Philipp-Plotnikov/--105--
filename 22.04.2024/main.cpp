#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "matrix.hpp"

using namespace std;

const string SOURCE_FILENAME = "./source.txt";
const string DESTINATION_FILENAME = "./destination.txt";

int getMatrixAmount(ifstream& file) {
    string line, temp;
    int matrixAmount = 0;
    getline(file, line);
    stringstream ss(line);
    while (ss >> temp) {
        if (stringstream(temp) >> matrixAmount) {
            break;
        }
    }
    cout << "Matrix amount: " << matrixAmount << endl;
    return matrixAmount;
}

int getMatrixDimesion(ifstream& file) {
    string line, temp;
    int size = 0;
    getline(file, line);
    stringstream ss(line);
    while (ss >> temp) {
        if (stringstream(temp) >> size) {
            break;
        }
    }
    cout << "Matrix size: " << size << endl;
    return size;
}

void setMatrix(Matrix* matrix, int size, ifstream& file) {
    string line;
    double value;
    matrix->Allocate(size);
    for (int i = 0; i < size; i++) {
        if (getline(file, line)) {
            stringstream ss(line);
            for (int j = 0; j < size; j++) {
                if (ss >> value) {
                    (*matrix)[i][j] = value;
                }
            }
        }
    }
}

void HoareSort(Matrix** array, int left, int right) {
    int l = left;
    int r = right;
    Matrix* mid = array[(l + r) / 2];
    do {
        while (array[l]->GetTrace() > mid->GetTrace())
            ++l;
        while (array[r]->GetTrace() < mid->GetTrace())
            --r;
        if (l <= r) {
            swap(array[l], array[r]);
            ++l;
            --r;
        }
    } while (l < r);
        if (left < r)
            HoareSort(array, left, r);
        if (l < right)
            HoareSort(array, l, right);
    }

void sortMatrixByTrace(Matrix** matrixList, int matrixAmount) {
    HoareSort(matrixList, 0, matrixAmount - 1);
}

int main() {
    ifstream source(SOURCE_FILENAME);
    int matrixAmount = getMatrixAmount(source);
    Matrix** matrixList = new Matrix*[matrixAmount];
    for (int i = 0; i < matrixAmount; i++) {
        matrixList[i] = new Matrix();
    }
    Matrix** symmetricMatrixList = new Matrix*[matrixAmount];
    int idx = 0;
    while (!source.eof()) {
        int size = getMatrixDimesion(source);
        Matrix* matrix = matrixList[idx++];
        setMatrix(matrix, size, source);
    }
    source.close();
    int symmetricMatrixAmount = 0;
    for (int i = 0; i < matrixAmount; i++) {
        Matrix* matrix = matrixList[i];
        if (matrix->isSymmetric() == 1) {
            symmetricMatrixList[symmetricMatrixAmount++] = matrix;
        }
    }
    delete[] matrixList;
    sortMatrixByTrace(symmetricMatrixList, symmetricMatrixAmount);
    ofstream destination(DESTINATION_FILENAME);
    for (int i = 0; i < symmetricMatrixAmount; i++) {
        Matrix* matrix = symmetricMatrixList[i];
        destination << "Matrix " << matrix->GetSize() << "x" << matrix->GetSize() << endl;
        destination << "Trace: " << matrix->GetTrace() << endl;
        for (int j = 0; j < matrix->GetSize(); j++) {
            for (int k = 0; k < matrix->GetSize(); k++) {
                destination << setw(4) << left << (*matrix)[j][k] << "\t";
            }
            destination << endl;
        }
        destination << endl;
    }
    destination.close();
    return 0;
}