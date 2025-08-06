#include "number_theory.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {

    int i;
    for (i = 1; partition(i) % 1000000 != 0; i++) {}
    assert(i == 55374);

    return 0;
}
