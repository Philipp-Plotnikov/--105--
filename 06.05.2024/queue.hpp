class Item {
private:
    long arrive;
    int processtime;
public:
    Item();

    void set(long when);

    long when() const;

    int ptime() const;
};