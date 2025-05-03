#include "prime.h"
#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include "macros.h"

using namespace std;

inline uint64_t t(uint64_t n) {
    return 2 * n * n - 1;
}

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    static const unsigned int MAX = 10000;
    map<unsigned int, unsigned int> seen;
    for (PrimeIterator pit(MAX); *pit < 10000; ++pit) {
        if (!(*pit % 8 == 1 || *pit % 8 == 7))
            continue;
    }

    // MAX - sum 2 * MAX/p for p = 1,7 mod 8

    return 0;
}
