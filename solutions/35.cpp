#include "prime.h"
#include "strint.h"
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;
int main (int argc, char *argv[]) {
    int total = 0;
    for (PrimeIterator pit; *pit < 1000000; ++pit) {
        vector<int> digits = get_digits(*pit);
        bool is_circular_prime = true;
        for (int i = 0; i < digits.size(); i++) {
            vector<int> rotations(digits.size());
            rotate_copy(digits.begin(), digits.begin() + i, digits.end(), rotations.begin());
            uint64_t prime_check = concat(rotations.begin(), rotations.end());
            if (!is_prime(prime_check)) {
                is_circular_prime = false;
                break;
            }
        }
        if (is_circular_prime) {
            total++;
        }
    }
    assert(total == 55);
    return 0;
}
