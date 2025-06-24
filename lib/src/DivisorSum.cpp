#include "prime.h"
#include "number_theory.h"

DivisorSum::DivisorSum(unsigned int max) {
    if (max == 0) {
        return;
    }
    this->lookup.reserve(max);

    lookup[0] = 1;
    for (size_t n = 1; n <= max; n++) {
        unsigned int count = 0;
        int multiplier = -1;
        for (GeneralizedPentagonal git; *git <= n; ++git) {
            if (count % 2 == 0) multiplier *= -1;
            lookup[n] += multiplier * ((*git == n) ? n : lookup[n - *git]);
            count++;
        }
    }
}

unsigned int DivisorSum::at(unsigned int val) {
    return this->lookup[val];
}

unsigned int DivisorSum::at_proper(unsigned int val) {
    return this->lookup[val] - val;
}
