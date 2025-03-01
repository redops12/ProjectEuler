#include "prime.h"
#include <cstdint>
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char *argv[]) {
    PrimeIterator it;
    uint64_t num = 0;
    while (*it < 2000000) {
        num += *it;
        ++it;
    }
    assert(num == 142913828922);
    return 0;
}
