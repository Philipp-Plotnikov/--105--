#include <iostream>

using namespace std;

int N = 0;

class White {
    class Gray {
    public:
        int value;
        White* child1;

        void OutputGray() {
            cout << "gray element: " << this << ", value: " << value << endl;
        }

        Gray() {
            cout << "gray element is created: " << this << endl;
            value = N++;
        }

        ~Gray() {
            cout << "gray element is deleted: " << this << endl;
        }
    };
    int value;
    Gray *child1, *child2;

    void OutputWhite() {
        cout << "white element: " << this << ", value: " << value << endl;
    }

public:
    White(int n) {
        cout << "white element is created: " << this << endl;
        value = N++;
        child1 = new Gray();
        child2 = new Gray();
        if (n > 1) {
            child1->child1 = new White(n-1);
            child2->child1 = child1->child1;
        } else {
            child1->child1 = nullptr;
            child2->child1 = nullptr;
        }
    }

    void OutputDList() {
        OutputWhite();
        child1->OutputGray();
        child2->OutputGray();
        if (child1->child1 != nullptr) {
            child1->child1->OutputDList();
        }
    }

    ~White() {
        cout << "white element is deleted: " << this << endl;
        White *grandChild = child1->child1;
        delete child1;
        delete child2;
        if (grandChild != nullptr) {
            delete grandChild;
        }
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    White obj(n);
    obj.OutputDList();
    return 0;
}