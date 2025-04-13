#include "prime.h"
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int64_t num = 1;
    for (PrimeIterator pit(10000000); ; ++pit) {
        num *= *pit;
        if (!is_prime(num + 1)) {
            assert(num + 1 == 30031);
            break;
        }
    }

    return 0;
}
