#pragma once

class Vector {
    double x, y, z;

public:
    Vector(double x, double y, double z);

    double GetLength();

    void OutputVector();

    double GetDistance(Vector* vector);
};