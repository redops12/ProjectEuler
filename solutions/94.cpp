#include <iostream>
#include <cassert>
#include "prime.h"
#include "strint.h"
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t total = 0;
    for (int n = 3; 3 * n - 1 < 1000000000; n++) {
        uint64_t candidate = 3;
        candidate *= n;
        candidate *= n;
        candidate -= 2*n + 1;
        if (candidate % 4 == 0 && fast_is_square(candidate)) {
            total += 3 * n + 1;
        }
        candidate = 3;
        candidate *= n;
        candidate *= n;
        candidate += 2*n - 1;
        if (candidate % 4 == 0 && fast_is_square(candidate)) {
            total += 3 * n - 1;
        }
    }
    assert(total == 518408346);

    return 0;
}
