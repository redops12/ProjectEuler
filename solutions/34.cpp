#include "combinatorics.h"
#include "strint.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
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
