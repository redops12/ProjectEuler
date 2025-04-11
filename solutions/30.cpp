#include "strint.h"
#include <iostream>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t grand_sum = 0;
    for (int i = 2; i < 300000; i++) {
        int sum = 0;
        for (DigIterator<int> it(i); it != it.end(); ++it) {
            sum += *it * *it * *it * *it * *it;
        }
        if (sum == i) {
            grand_sum += i;
        }
    }
    assert(grand_sum == 443839);
    return 0;
}
