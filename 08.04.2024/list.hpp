#include "vector.hpp"
#include "node.hpp"

class MyList {
    int s;
    Node* head, *tail;

public:
    MyList();

    void push_back(int label, Vector* vector);

    void pop_front();

    void clear();

    void OutputList();

    int GetSize();

    Node* GetHead();

    ~MyList();
};