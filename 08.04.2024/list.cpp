#include "list.hpp"
#include <iostream>

MyList::MyList() {
    s = 0;
    head = tail = nullptr;
}

void MyList::push_back(int label, Vector* vector) {
    Node* node = new Node(label, vector);
    if (head == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    s++;
}

void MyList::pop_front() {
    if (!head) {
        std::cout << "pop_front error" << std::endl;
        exit(1);
    }
    Node* pTemp = head;
    head = head->next;
    delete pTemp;
    head->prev = nullptr;
    s--;
}

void MyList::clear() {
    for (int i = 0; i < s; i++) {
        pop_front();
    }
}

MyList::~MyList() {
    clear();
}

void MyList::OutputList() {
    Node* node = head;
    for (int i = 0; i < s; i++) {
        node->OutputNode();
        node = node->next;
    }
}

int MyList::GetSize() {
    return s;
}

Node* MyList::GetHead() {
    return head;
}