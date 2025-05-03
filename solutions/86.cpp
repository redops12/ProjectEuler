#include "prime.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    unsigned int prev_count = 0;

    size_t M = 1;
    while (prev_count < 1000000) {
        M++;
        // skip double count by assuming at least one side is length M
        // always combine the two smaller side lengths which at most will be 2M - 1 since
        // 5M^2 will never be a perfect square
        for (size_t sum = 2; sum <= 2 * M - 1; sum++) {
            if (fast_is_square(M * M + sum * sum)) {
                if (sum > M) {
                    prev_count += (2 * M - sum) / 2 + 1;
                } else {
                    prev_count += sum / 2;
                }
            }
        }
    }
    assert(M == 1818);

    return 0;
}
