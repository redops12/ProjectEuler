#include "prime.h"
#include "strint.h"
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int main() {
    PrimeIterator pit;
    while (*pit < 1000) {++pit;}
    for (;*pit < 10000; ++pit) {
        vector<unsigned int> digs = get_digits(*pit);
        set<int> difference;
        while (next_permutation(digs.begin(), digs.end())) {
            uint64_t new_p = concat(digs.begin(), digs.end());
            if (is_prime(new_p)) {
                difference.insert(abs(static_cast<int>(new_p - *pit)));
            }
        }
        if (difference.size() < 2) continue;
        for (auto p : difference) {
            if (difference.find(2 * p) != difference.end()) {
                assert(*pit == 2969 || *pit == 1487);
            }
        }
    }
    return 0;
}
