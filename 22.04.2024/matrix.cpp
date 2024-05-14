#include "matrix.hpp"
#include <iostream>

Matrix::Matrix() {
    size = 0;
    matrix = nullptr;
}

Matrix::Matrix(int size) {
    Allocate(size);
}

void Matrix::Allocate(int size) {
    std::cout << "Allocate matrix " << size << "x" << size << std::endl;
    this->size = size;
    matrix = new double*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size]{0};
    }
}

void Matrix::clear() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double Matrix::GetTrace() {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += matrix[i][i];
    }
    return result;
}

double* Matrix::operator[](int idx) {
    if (idx < 0 || idx >= size) {
        std::cout << "idx: " << idx << "is not correct for matrix " << size << "x" << size << std::endl;
        exit(1);
    }
    return matrix[idx];
}

int Matrix::isSymmetric() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

void Matrix::PrintMatrix() {
    std::cout << "Matrix " << size << "x" << size << std::endl;
    std::cout << "Trace: " << GetTrace() << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::GetSize() {
    return size;
}

Matrix::~Matrix() {
    clear();
}