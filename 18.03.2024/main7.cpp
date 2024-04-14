#include <iostream>

using namespace std;

int N = 0;

class White {
    class Gray {
    public:
        int value;
        Gray* child1;

        void OutputGray() {
            cout << "gray element: " << this << ", value: " << value << endl;
        }

        void OutputDList() {
            OutputGray();
            if (child1 != nullptr) {
                child1->OutputDList();
            }
        }

        Gray(int n) {
            cout << "gray element is created: " << this << endl;
            value = N++;
            if (n > 1) {
                child1 = new Gray(n-1);
            } else {
                child1 = nullptr;
            }
        }

        ~Gray() {
            cout << "gray element is deleted: " << this << endl;
            delete child1;
        }
    };
    int value;
    White* child1;
    Gray* child2;

    void OutputWhite() {
        cout << "white element: " << this << ", value: " << value << endl;
    }

public:
    White(int n) {
        cout << "white element is created: " << this << endl;
        value = N++;
        if (n > 1) {
            child1 = new White(n-1);
            child2 = new Gray(n-1);
        } else {
            child1 = nullptr;
            child2 = nullptr;
        }
    }

    void OutputDList() {
        OutputWhite();
        if (child1 != nullptr) {
            child1->OutputDList();
            child2->OutputDList();
        }
    }

    ~White() {
        cout << "white element is deleted: " << this << endl;
        delete child1;
        delete child2;
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