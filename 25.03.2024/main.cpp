#include <iostream>

using namespace std;

int N = 0;

class White {
    class Gray {
    public:
        int m;
        Gray *pr;
        White *pb;
    
        void OutputGray() {
            cout << "Gray element: " << this << ", value: " << m << endl;
        }

        Gray() {
            cout << "Gray is created: " << this << endl;
            m = N++;
            pr = nullptr;
            pb = nullptr;
        }

        ~Gray() {
            cout << "Gray is deleted: " << this << endl;
        }
    };

    int m;
    int size;
    Gray *pb;

    void OutputWhite() {
        cout << "White element: " << this << ", value: " << m << endl;
    }

    White() {
        cout << "White is created: " << this << endl;
        m = N++;
        pb = nullptr;
    }

public:
    White(int n) {
        cout << "White is created: " << this << endl;
        m = N++;
        White* topHead = new White();
        pb = new Gray();
        pb->pr = new Gray();
        pb->pr->pr = pb;
        topHead->pb = pb->pr;
        Gray* currentHead1 = pb;
        Gray* currentHead2 = topHead->pb;
        for (int i = 0; i < n - 1; i++) {
            currentHead1->pb = new White();
            currentHead2->pb = new White();
            currentHead1->pb->pb = new Gray();
            currentHead1->pb->pb->pr = new Gray();
            currentHead1->pb->pb->pr->pr = currentHead1->pb->pb;
            currentHead2->pb->pb = currentHead1->pb->pb->pr;
            currentHead1 = currentHead1->pb->pb;
            currentHead2 = currentHead2->pb->pb;
        }
        currentHead1->pb = this;
        currentHead2->pb = topHead;
        size = N;
    }

    void OutputDList() {
        static int s = size;
        OutputWhite();
        pb->OutputGray();
        s -= 2;
        if (s == 0) {
            return;
        }
        if (s == (size + 1) / 2) {
            pb->pr->pb->OutputDList();
            return;
        }
        pb->pb->OutputDList();
    }

    ~White(){
        static int s = size;
        cout << "White element is deleted: " << this << endl;
        White* temp1 = pb->pb;
        White* temp2 = pb->pr->pb;
        delete pb;
        s -= 2;
        if (s == 0) {
            return;
        }
        if (s == (size + 1) / 2) {
            delete temp2;
            return;
        }
        delete temp1;
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