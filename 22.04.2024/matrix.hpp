#pragma once

class Matrix {
    int size;
    double** matrix;

    void clear();
public:
    Matrix();

    Matrix(int size);

    void Allocate(int size);

    double GetTrace();

    double* operator[](int idx);

    int isSymmetric();

    void PrintMatrix();

    int GetSize();

    ~Matrix();
};