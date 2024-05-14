#include <iostream>

using namespace std;

int N = 0;

class DList {
    int value, size;
    DList* child1;
    //int isLast = 0;

    void OutputElement() {
        cout << "element: " << this << ", value: " << value << endl;
    }

    DList() {
        cout << "element created: " << this << endl;
        value = N++;
    }

public:

    DList(int n) {
        size = n;
        cout << "element created: " << this << endl;
        value = N++;
        DList* q0 = this, * q1;
        for (int i = 1; i < n; i++) {
            q1 = new DList;
            q0->child1 = q1;
            q0 = q1;
        }
        q0 = this;
    }

    /*DList(int n, DList* head = nullptr) {
        cout << "element created: " << this << endl;
        value = N++;
        if (head == nullptr) {
            head = this;
        }
        if (n > 1) {
            child1 = new DList(n - 1, head);
        } else {
            this->child1 = head;
            isLast = 1;
        }
    }*/

    void OutputDList() {
        static int s = 2 * size;
        OutputElement();
        if (s > 0) {
            cout << "s = " << s << endl;
            s--;
            child1->OutputDList();
        }
    }

    /*void OutputDList() {
        OutputElement();
        if (child1 != nullptr && this->isLast != 1) {
            child1->OutputDList();
        }
    }*/

    /*~DList() {
        cout << "element deleted: " << this << endl;
        if (this->isLast != 1) {
            delete child1;
        }
    }*/
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    DList obj(n);
    obj.OutputDList();
    return 0;
}