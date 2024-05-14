#include <iostream>

using namespace std;

int N = 0;

const int GENERAL_NODE = 1;
const int TOP_LEFT_NODE = 2;
const int TOP_RIGHT_NODE = 3;
const int BOTTOM_LEFT_NODE = 4;
const int BOTTOM_RIGHT_NODE = 5;

class DList {
    int m;
    DList *pl, *pr;
    int nodeType;

    void OutputElement() {
        cout << "element: " << this << ", value: " << m << endl;
    }

    DList(int nodeType) {
        cout << "Element is created: " << this << endl;
        this->nodeType = nodeType;
        m = N++;
    }
public:
    DList(int n, int nodeType) {
        cout << "Element is created: " << this << endl;
        this->nodeType = nodeType;
        m = N++;
        pl = new DList(TOP_LEFT_NODE);
        pr = new DList(TOP_RIGHT_NODE);
        pl->pr = pr;
        pl->pl = new DList(BOTTOM_LEFT_NODE);

        pr->pl = pl;
        pr->pr = new DList(BOTTOM_RIGHT_NODE);

        pl->pl->pr = pr->pr;
        pr->pr->pl = pl->pl;
        if (n > 1) {
            pl->pl->pl = new DList(n-1, GENERAL_NODE);
            pr->pr->pr = pl->pl->pl;
        } else {
            pl->pl->pl = nullptr;
            pr->pr->pr = nullptr;
        }
    }

    void OutputDList() {
        OutputElement();
        pl->OutputElement();
        pr->OutputElement();
        pl->pl->OutputElement();
        pr->pr->OutputElement();
        if (pl->pl->pl != nullptr) {
            pl->pl->pl->OutputDList();
        }
    }

    ~DList() {
        cout << "Element is deleted: " << this << endl;
        if (nodeType == GENERAL_NODE) delete pl;
        if (nodeType == TOP_LEFT_NODE) delete pr;
        if (nodeType == TOP_RIGHT_NODE) delete pr;
        if (nodeType == BOTTOM_RIGHT_NODE) delete pl;
        if (nodeType == BOTTOM_LEFT_NODE && pl != nullptr) delete pl;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    DList obj(n, GENERAL_NODE);
    obj.OutputDList();
    return 0;
}