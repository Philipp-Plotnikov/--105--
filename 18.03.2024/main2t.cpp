#include <iostream>

using namespace std;

int N = 0;

class DList {
    int m;
    DList *pl, *pr;

    void OutputElement() {
        cout << "element: " << this << ", value: " << m << endl;
    }

    DList() {
        cout << "Element is created: " << this << endl;
        m = N++;
    }
public:
    DList(int n) {
        cout << "Element is created: " << this << endl;
        m = N++;
        pl = new DList();
        pr = new DList();
        pr->pr = pl;
        pr->pl = new DList();

        pl->pr = pr;
        pl->pl = new DList();


        pl->pl->pr = pr->pl;
        pr->pl->pr = pl->pl;
        if (n > 1) {
            pl->pl->pl = new DList(n-1);
            pr->pl->pl = pl->pl->pl;
        } else {
            pl->pl->pl = nullptr;
            pr->pl->pl = nullptr;
        }
    }

    void OutputDList() {
        OutputElement();
        pl->OutputElement();
        pr->OutputElement();
        pr->pl->OutputElement();
        pl->pl->OutputElement();
        if (pl->pl->pl != nullptr) {
            pl->pl->pl->OutputDList();
        }
    }

    ~DList() {
        cout << "Element is deleted: " << this << endl;
        if (pl == nullptr) {
            if (pr->p == this) {
                delete pr;
            }
            return;
        }
        if (pl != ) {
            delete pr;
            return;
        }
        if () {

        }
        // if (m % 2 == 0) {
        //     if (pl != nullptr) {
        //         delete pl;
        //     }
        //     return;
        // }
        // if (pr != nullptr) {
        //     delete pr;
        // }
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    DList obj(n);
    obj.OutputDList();
    return 0;
}