#include <iostream>

using namespace std;

class MyList {
    class Node {
    public:
        int m;
        Node* next, *prev;

        Node(int N) {
            m = N;
            next = nullptr;
            prev = nullptr;
        }
    };

    int s;
    Node* head, *tail;

    void Swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void HoareSort(int* array, int left, int right) {
        int l = left;
        int r = right;
        int mid = array[(l + r) / 2];
        do {
            while (array[l] < mid)
                ++l;
            while (array[r] > mid)
                --r;
            if (l <= r) {
                Swap(array[l], array[r]);
                ++l;
                --r;
            }
        } while (l < r);
        if (left < r)
            HoareSort(array, left, r);
        if (l < right)
            HoareSort(array, l, right);
    }
public:
    MyList() {
        s = 0;
        head = tail = nullptr;
    }

    void push_back(int n) {
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

    void OutputDList() {
        Node* node = head;
        for (int i = 0; i < s; i++) {
            cout << node->m << ' ';
            node = node->next;
        }
        cout << endl;
    }

    void sort() {
        int* array = new int[s] {0};
        Node* pTemp = head;
        for (int i = 0; i < s; i++) {
            array[i] = pTemp->m;
            pTemp = pTemp->next;
        }
        HoareSort(array, 0, s-1);
        pTemp = head;
        for (int i = 0; i < s; i++) {
            pTemp->m = array[i];
            pTemp = pTemp->next;
        }
        delete[] array;
    }

    void pop_front() {
        if (!head) {
            cout << "pop_front error" << endl;
            exit(1);
        }
        Node* pTemp = head;
        head = head->next;
        delete pTemp;
        head->prev = nullptr;
        s--;
    }

    void clear() {
        for (int i = 0; i < s; i++) {
            pop_front();
        }
    }

    ~MyList() {
        clear();
    }
};

int main() {
    MyList myObj;
    myObj.push_back(5);
    myObj.push_back(-7);
    myObj.push_back(10);
    myObj.push_back(12);
    myObj.push_back(16);
    myObj.push_back(-3);
    myObj.push_back(8);
    myObj.push_back(-10);
    myObj.sort();
    myObj.OutputDList();
    return 0;
}