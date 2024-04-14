#pragma once
#include "vector.hpp"

class Node {
public:
    int label;
    Vector* vector;
    Node* next, *prev;

    Node(int label, Vector* vector);

    void OutputNode();
};