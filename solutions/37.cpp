#include "strint.h"
#include "prime.h"
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char *argv[]) {
    PrimeIterator pit;
    int sum = 0;
    while (*pit < 10) ++pit; // skip single digits
    for (int num_found = 0; num_found < 11; ++pit) {
        vector<int> digs = get_digits(*pit);
        bool truncatable = true;
        for (int i = 1; i < digs.size(); i++) {
            if (!is_prime(concat(digs.begin() + i, digs.end())) ||
                !is_prime(concat(digs.begin(), digs.end() - i)))
            {
                truncatable = false;
                break;
            }
        }
        if (truncatable) {
            num_found++;
            sum += *pit;
        }
    }
    assert(sum == 748317);
    return 0;
}
