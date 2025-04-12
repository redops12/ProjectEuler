#include "prime.h"
#include "strint.h"
#include <iostream>
#include <cassert>
#include <set>
#include <optional>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    for (PrimeIterator pit;;++pit) {
        vector<unsigned int> digs = get_digits(*pit);
        for (size_t i = 1; i < digs.size(); i++) {
            vector<int> mask;
            for (size_t j = 0; j < digs.size(); j++) {
                if (j < i) mask.push_back(0);
                else mask.push_back(1);
            }
            do {
                bool bad_mask = false;
                optional<unsigned int> dig;
                for (size_t j = 0; j < digs.size(); j++) {
                    if (mask[j] == 0) continue;
                    if (dig) {
                        if (dig > 2) {
                            bad_mask = true;
                            break;
                        }
                        dig = digs[j];
                    }
                    else if (digs[j] != dig) {
                        bad_mask = true;
                        break;
                    }
                }
                if (bad_mask) continue;
                uint64_t inc = concat(mask.begin(), mask.end());
                uint64_t test_prime = *pit - inc * ((mask.front() == 1) ? *dig - 1 : *dig);
                int count = 0;
                for (int i = 0; i < 10; i++){
                    if (is_prime(test_prime)) {
                        count++;
                    }
                    test_prime += inc;
                }
                if (count >= 8) {
                    assert(*pit == 121313);
                    return 0;
                }
            } while (next_permutation(mask.begin(), mask.end()));
        }
    }

    return 0;
}
