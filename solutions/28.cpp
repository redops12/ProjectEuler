#include <iostream>
#include <cstdint>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t sum = 1;
    uint64_t corner = 1;
    for (int i = 1; i < 1001 / 2 + 1; i++) {
        for (int j = 0; j < 4; j++) {
            corner += i * 2;
            sum += corner;
        }
    }
    cout << sum << endl;
    return 0;
}
