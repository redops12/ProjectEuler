#include "prime.h"
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int main() {
    set<unsigned int> seen;

    const unsigned int MAX = 50000000;
    PrimeIterator pit(7072);
    for (PrimeIterator pit1; *pit1 * *pit1 < MAX; ++pit1) {
        unsigned int limit1 = MAX - (*pit1 * *pit1);
        for (PrimeIterator pit2; *pit2 * *pit2 * *pit2 < limit1; ++pit2) {
            unsigned int limit2 = limit1 - (*pit2 * *pit2 * *pit2);
            for (PrimeIterator pit3; *pit3 * *pit3 * *pit3 * *pit3 < limit2; ++pit3) {
                unsigned int new_num =
                            *pit1 * *pit1 +
                            *pit2 * *pit2 * *pit2 +
                            *pit3 * *pit3 * *pit3 * *pit3;
                seen.insert(new_num);
            }
        }
    }

    assert(seen.size() == 1097343);

    return 0;
}
