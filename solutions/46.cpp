#include "prime.h"
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    for (size_t i = 33; true; i+=2) {
        if (is_prime(i)) continue;
        bool counter_example = true;
        PrimeIterator pit;
        ++pit;
        for (; *pit < i; ++pit) {
            if (fast_is_square((i - *pit) / 2)) {
                counter_example = false;
                break;
            }
        }
        if (counter_example) {
            assert(i == 5777);
            break;
        }
    }

    return 0;
}
