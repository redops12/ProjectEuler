#include <cassert>
#include "prime.h"
#include "number_theory.h"

int main(int argc, char * argv[]) {
    Factorized f1(2);
    assert(!f1.is_square());
    assert(!fast_is_square(2));
    Factorized f2(4);
    assert(f2.is_square());
    assert(fast_is_square(4));
    Factorized f3(6);
    assert(!f3.is_square());
    assert(!fast_is_square(6));
    Factorized f4(36);
    assert(f4.is_square());
    assert(fast_is_square(36));

    ContinuedFrac c23(23);
    assert(c23.initial == 4);
    assert(c23.repeated[0] == 1);
    assert(c23.repeated[1] == 3);
    assert(c23.repeated[2] == 1);
    assert(c23.repeated[3] == 8);
    ContinuedFrac c2(2);
    assert(c2.repeated.size() == 1);
    ContinuedFrac c3(3);
    assert(c3.repeated.size() == 2);
    ContinuedFrac c5(5);
    assert(c5.repeated.size() == 1);
    ContinuedFrac c6(6);
    assert(c6.repeated.size() == 2);
}
