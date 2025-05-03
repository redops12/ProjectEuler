#include "number_theory.h"
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int i;
    for (i = 1; partition(i) % 1000000 != 0; i++) {}
    assert(i == 55374);

    return 0;
}
