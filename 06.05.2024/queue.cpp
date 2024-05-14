#include <cstdlib>
#include "queue.hpp"

Item::Item() {
    arrive = processtime = 0;
}

void Item::set(long when) {
    processtime = rand() % 3 + 1;
    arrive = when;
}

long Item::when() const {
        return arrive;
    }

int Item::ptime() const {
    return processtime;
}