#include <iostream>

using namespace std;

int N = 0;

class Grey {
    class White {
    public:
        int value;
        White* child1;

        void OutputWhite() {
            cout << "white element: " << this << ", value: " << value << endl;
        }

        White() {
            cout << "white element created: " << this << endl;
            value = N++;
        }

        ~White() {
            cout << "white element deleted: " << this << endl;
        }
    };
    int value;
    White* child1;
    Grey* child2;

    void OutputGrey() {
        cout << "grey element: " << this << ", value: " << value << endl;
    }

public:
    Grey(int n) {
        cout << "grey element created: " << this << endl;
        value = N++;
        child1 = new White();
        if (n > 1) {
            child2 = new Grey(n - 1);
            child1->child1 = child2->child1;
        } else {
            child2 = nullptr;
        }
    }

    void OutputDList() {
        OutputGrey();
        child1->OutputWhite();
        if (child2 != nullptr) {
            child2->OutputDList();
        }
    }

    ~Grey() {
        cout << "grey element deleted: " << this << endl;
        delete child1;
        delete child2;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    Grey obj(n);
    obj.OutputDList();
    return 0;
}