#include "combinatorics.h"
#include "strint.h"
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int grand_sum = 0;
    for (int i = 3; i < 100000; i++) {
        int sum = 0;
        for (DigIterator<int> it(i); it != it.end(); ++it) {
            sum += static_cast<int>(factorial(*it));
        }
        if (sum == i) {
            grand_sum += i;
        }
    }
    assert(grand_sum == 40730);
    return 0;
}
