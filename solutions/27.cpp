#include "prime.h"
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char *argv[]) {
    int max_n = 0, max_a, max_b;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n;
            for (n = 0; is_prime(n * n + a * n + b); n++) {}
            if (n > max_n) {
                max_n = n;
                max_a = a;
                max_b = b;
            }
        }
    }

    assert(max_a * max_b == -59231);
    return 0;
}
