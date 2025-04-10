#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <cstdint>

using namespace std;

int main (int argc, char *argv[]) {
    unordered_set<uint64_t> fracs;
    fracs.reserve(1000000);
    for (size_t i = 1; i <= 12000; i++) {
        for (size_t j = (i + 1) / 3; j < (i + 1) / 2; j++) {
            // j/i > 1/3
            if (3 * j <= i) continue;
            if (2 * j >= i) continue;
            size_t g = gcd(i, j);
            fracs.insert(((j / g) << 32) + (i / g));
        }
    }
    assert(fracs.size() == 7295372);

    return 0;
}
