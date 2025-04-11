#include "strint.h"
#include <iostream>
#include "macros.h"

using namespace boost::multiprecision;
using namespace std;


int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    cpp_int fac = 1;
    for (int i = 2; i <= 100; i++) {
        fac *= i;
    }
    assert(sum_digits(fac) == 648);
    return 0;
}
