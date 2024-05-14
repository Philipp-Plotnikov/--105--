class MyList {
    class Node {
    public:
        int m;
        int amount;
        Node* next, *prev;

        Node(int N);
    };

    int s;
    Node* head, *tail;

public:
    MyList();

    void push_back(int n);

    void push(int n);

    void OutputDList();

    void pop_front();

    void clear();

    ~MyList();
};