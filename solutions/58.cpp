#include "prime.h"
#include <iostream>
#include <cassert>
#include <cstdint>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t total = 1;
    uint64_t prime = 0;
    uint64_t corner = 1;
    for (int i = 1; ; i++) {
        for (int j = 0; j < 4; j++) {
            corner += i * 2;
            if (is_prime(corner)) {
                prime++;
            }
            total++;
            if (total > prime * 10) {
                assert(26241 == i * 2 + 1);
                return 0;
            }
        }
    }
    return 0;
}
