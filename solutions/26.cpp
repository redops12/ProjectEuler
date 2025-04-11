#include <map>
#include <iostream>
#include <cassert>
#include "macros.h"

using namespace std;

int main(int argc, char * argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int max_length_cycle = 0, max_d;
    for (int d = 1; d < 1000; d++) {
        map<int, int> seen;
        int num = 1, idx = 0;
        while (num != 0 && seen.find(num) == seen.end()) {
            seen[num] = idx;
            num *= 10;
            num %= d;
            idx++;
        }
        // terminating sequence
        if (num == 0) continue;
        int length = idx - seen[num];
        if (length > max_length_cycle) {
            max_length_cycle = length;
            max_d = d;
        }
    }
    assert(max_d == 983);
    return 0;
}
