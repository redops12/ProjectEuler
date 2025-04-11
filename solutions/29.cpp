#include "prime.h"
#include <set>
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    set<Factorized> seen;
    for (int a = 2; a <= 100; a++) {
        Factorized f(a);
        for (int b = 2; b <= 100; b++) {
            Factorized c = f;
            c.power_of(b);
            seen.insert(c);
        }
    }
    assert(seen.size() == 9183);
    return 0;
}
