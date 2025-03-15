#include "strint.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    uint64_t max_ret = 0;
    for (int n = 2; n < 6; n++) {
        int max_val = pow(10, 10 / n + 1);
        for (int i = 1; i < max_val; i++) {
            uint64_t num = i;
            for (int j = 2; j <= n; j++) {
                num = concat_num(num, j * i);
            }
            if (is_pandigital(num)) {
                max_ret = max(max_ret, num);
            }
        }
    }
    assert(max_ret == 932718654);
}
