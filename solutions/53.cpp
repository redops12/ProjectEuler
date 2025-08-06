#include "combinatorics.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int count = 0;
    for (size_t n = 0; n <= 100; n++) {
        for (size_t r = 0; r < n; r++) {
            if (n_choose_r(n, r) > 1000000) {
                count++;
            }
        }
    }
    assert(count == 4075);
    return 0;
}
