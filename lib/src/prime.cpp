#include <vector>
#include "prime.h"
#include <algorithm>

using std::vector;
using std::binary_search;
using std::copy;

static vector<int> known_primes = {2};

PrimeIterator::PrimeIterator():idx(0) {}

int PrimeIterator::operator*() const {
    return known_primes[idx];
}

PrimeIterator& PrimeIterator::operator++() {
    if (idx == known_primes.size() - 1) {
        int num = known_primes[idx] + 1;
        while (true)
        {
            if (is_prime(num)) {
                known_primes.push_back(num);
                idx++;
                break;
            }

            num++;
        }
    } else {
        idx++;
    }
    return *this;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return this->idx != other.idx;
}

PrimeIterator PrimeIterator::operator+(int offset) {
    PrimeIterator prime_copy = *this;
    for (int i = 0; i < offset; i++) {
        ++prime_copy;
    }
    return prime_copy;
}

bool is_prime(uint64_t num) {
    if (num < known_primes.back()) {
        return binary_search(known_primes.begin(), known_primes.end(), num);
    }
    for (auto p : known_primes) {
        if (p * p > num) {
            break;
        }
        if (num % p == 0) {
            return false;
            break;
        }
    }
    return true;
}
