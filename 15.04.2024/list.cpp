#include "list.hpp"
#include <iostream>

MyList::Node::Node(int N) {
    m = N;
    amount = 1;
    next = nullptr;
    prev = nullptr;
}

MyList::MyList() {
    s = 0;
    head = tail = nullptr;
}

void MyList::push_back(int n) {
    Node* node = new Node(n);
    if (head == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    s++;
}

void MyList::push(int n) {
    Node* pTemp = head;
    for (int i = 0; i < s; i++) {
        if (pTemp->m == n) {
            pTemp->amount++;
            return;
        }
        pTemp = pTemp->next;
    }
    push_back(n);
}

void MyList::OutputDList() {
    Node* node = head;
    for (int i = 0; i < s; i++) {
        std::cout << node->m << ' ' << "Repeats: " << node->amount << std::endl;
        node = node->next;
    }
    std::cout << std::endl;
}

void MyList::pop_front() {
    if (!head) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    s--;
}

void MyList::clear() {
    while (head) {
        pop_front();
    }
}

MyList::~MyList() {
    clear();
}