#include "vector.hpp"
#include <math.h>
#include <iostream>

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector::GetLength() {
    return sqrt(x * x + y * y + z * z);
}

void Vector::OutputVector() {
    std::cout << "Vector: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

double Vector::GetDistance(Vector* vector) {
    return sqrt(pow(x - vector->x, 2) + pow(y - vector->y, 2) + pow(z - vector->z, 2));
}