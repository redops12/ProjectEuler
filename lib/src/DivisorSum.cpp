#include "prime.h"
#include "number_theory.h"

DivisorSum::DivisorSum(unsigned int max) {
    if (max == 0) {
        return;
    }
    this->lookup.resize(max);

    lookup[0] = 1;
    for (size_t n = 1; n <= max; n++) {
        for (GeneralizedPentagonal git; *git <= n; ++git) {
            unsigned int n1,n2,n3;
            n1 = ((*git == n) ? n : lookup[n - *git]);
            ++git;
            if (*git > n) {
                lookup[n] += n1;
                break;
            }
            n2 = ((*git == n) ? n : lookup[n - *git]);
            ++git;
            if (*git > n) {
                lookup[n] += n1 + n2;
                break;
            }
            n3 = ((*git == n) ? n : lookup[n - *git]);
            ++git;
            if (*git > n) {
                lookup[n] += n1 + n2 - n3;
                break;
            }
            lookup[n] += n1 + n2 - n3 - ((*git == n) ? n : lookup[n - *git]);
        }
    }
}

unsigned int DivisorSum::at(unsigned int val) {
    return this->lookup[val];
}

unsigned int DivisorSum::at_proper(unsigned int val) {
    return this->lookup[val] - val;
}
