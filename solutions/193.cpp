#include "number_theory.h"
#include "prime.h"
#include <iostream>
#include <cstdint>
#include <cmath>
#include <array>
#include <cstring>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int64_t n = static_cast<uint64_t>(1) << 50;
    int64_t upper = static_cast<int64_t>(sqrt(n));
    const uint32_t max_d = upper + 1;
    Mobius m(max_d);
    int64_t sum = 0;
    for (int d = 1; d <= upper; d++) {
        sum += m.at(d) * n / (static_cast<int64_t>(d) * d);
    }

    assert(684465067343069 == sum);
    return 0;
}
