#include "number_theory.h"
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    static const int UPPER_BOUND = 1000000 + 1; // inclusive
    Totient t(UPPER_BOUND);
    uint64_t count = 0;
    for (int i = 2; i < UPPER_BOUND; i++) {
        count += t.at(i);
    }
    cout << count << endl;

    return 0;
}
