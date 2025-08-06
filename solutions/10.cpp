#include "prime.h"
#include <cstdint>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    PrimeIterator it(2000000);
    uint64_t num = 0;
    while (*it < 2000000) {
        num += *it;
        ++it;
    }
    assert(num == 142913828922);
    return 0;
}
