#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <cstdint>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t mod = 4503599627370517;
    uint64_t add = 1504170715041707;
    ExtendedEuclidean ex(static_cast<int64_t>(mod), static_cast<int64_t>(add));
    uint64_t inv = ex.y + mod;
    uint64_t base = add;
    uint64_t smallest = add;
    uint64_t sum = add; // algorithm misses initial value
    uint64_t stopping_coin = 258162;
    while (base != 0) {
        base += ((mod - base) / add + 1) * add;
        base %= mod;
        if (smallest > stopping_coin) {
            if (base < smallest) {
                uint64_t difference = smallest - base;
                uint64_t iterations = smallest / difference;
                // sum_0^iters smallest - k difference = (iters) / 2 (2 * smallest + (iters - 1)difference)
                sum += (iterations * (2 * base - (iterations - 1) * difference)) / 2;
                smallest %= difference;
            }
        } else {
            uint64_t smallest = mod;
            for (uint64_t i = 1; i < stopping_coin; i++) {
                uint64_t inverse_i = (i * inv) % mod;
                if (inverse_i < smallest) {
                    smallest = inverse_i;
                    sum += i;
                }
            }
            break;
        }
    }

    assert(sum == 1517926517777556);
    return 0;
}
