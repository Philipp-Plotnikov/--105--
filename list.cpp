#include <iostream>

using namespace std;

int N = 0;

struct ListElement {
    public:
        int value;
        ListElement* child1;
        ListElement* child2;
};

ListElement* CreateElement() {
    ListElement* newElement = new ListElement;
    cout << "element created: " << newElement << endl;
    newElement->value = N++;
    return newElement;
}

ListElement* CreateList(int n) {
    ListElement* head = CreateElement();
    ListElement* child1 = CreateElement();
    ListElement* child2 = CreateElement();
    ListElement* child3 = CreateElement();
    ListElement* child4 = CreateElement();
    head->child1 = child1;
    head->child2 = child2;

    child1->child1 = child2;
    child2->child1 = child1;

    child1->child2 = child3;
    child2->child2 = child4;

    child3->child1 = child4;
    child4->child1 = child3;

    if (n > 1) {
        child3->child2 = CreateList(n-1);
        child4->child2 = child3->child2;
    } else {
        child3->child2 = nullptr;
        child4->child2 = nullptr;
    }
    return head;
}

void PrintListElement(ListElement* element) {
    cout << "element: " << element << ", value=" << element->value << endl;
}

void PrintList(ListElement* element) {
    PrintListElement(element);
    PrintListElement(element->child1);
    PrintListElement(element->child2);
    PrintListElement(element->child1->child2);
    PrintListElement(element->child2->child2); 
    if (element->child1->child2->child2 != nullptr)
        PrintList(element->child1->child2->child2);
}

void DeleteListElement(ListElement* element) {
    cout << "element deleted: " << element << endl;
    delete element;
}

void DeleteList(ListElement* element) {
    if (element->child1->child2->child2 != nullptr)
        DeleteList(element->child1->child2->child2);
    DeleteListElement(element->child1->child2);
    DeleteListElement(element->child2->child2);
    DeleteListElement(element->child1);
    DeleteListElement(element->child2);
    DeleteListElement(element);
}

int main() {
    // n >= 1
    int n;
    cout << "Enter n:";
    cin >> n;
    ListElement* element = CreateList(n);
    PrintList(element);
    DeleteList(element);
    return 0;
}