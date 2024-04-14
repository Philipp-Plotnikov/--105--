#include "node.hpp"
#include <iostream>

Node::Node(int label, Vector* vector) {
    this->label = label;
    this->vector = vector;
    next = nullptr;
    prev = nullptr;
}

void Node::OutputNode() {
    std::cout << "Label: " << label << ", ";
    vector->OutputVector();
}