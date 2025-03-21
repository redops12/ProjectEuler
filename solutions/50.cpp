#include "prime.h"
#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char *argv[]) {
    int upper_bound = 547;
    int temp_upper_bound = 547;
    while (true) {
        PrimeIterator it_upper;
        int sum = 0;
        int i = 0;
        for (; i < temp_upper_bound; ++i) {
            sum += *it_upper;
            ++it_upper;
        }
        PrimeIterator it_lower;
        bool found = false;
        do {
            if (is_prime(sum)) {
                assert(sum == 997651);
                found = true;
                break;
            }
            sum -= *it_lower;
            sum += *it_upper;
            ++it_lower;
            ++it_upper;
            i++;
        } while (i < upper_bound);
        if (found) break;
        temp_upper_bound--;
        if (temp_upper_bound == 0) break;
    }

    return 0;
}
