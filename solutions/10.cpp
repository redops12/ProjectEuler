#include "prime.h"
#include <cstdint>
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    PrimeIterator it(2000000);
    uint64_t num = 0;
    while (*it < 2000000) {
        num += *it;
        ++it;
    }
    assert(num == 142913828922);
    return 0;
}
