#include "strint.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdint>
#include <bitset>

using namespace std;

int main (int argc, char *argv[]) {
    uint64_t sum = 0;
    for (int i = 1; i < 1000000; i++) {
        vector<int> base10 = get_digits(i, 10);
        vector<int> base2 = get_digits(i, 2);
        if (is_palindrome(base10) && is_palindrome(base2)) {
            sum += i;
        }
    }
    assert(sum == 872187);
    return 0;
}
