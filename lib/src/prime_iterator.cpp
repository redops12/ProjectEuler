#include <vector>
#include "prime.h"

using std::vector;

vector<uint64_t> known_primes = {2};
static vector<int> sieve;

PrimeIterator::PrimeIterator():idx(0) {}

PrimeIterator::PrimeIterator(uint64_t max_prime):idx(0) {
    if (max_prime + 1 > sieve.size()) {
        sieve.resize(max_prime + 1, 0);
    }
    for (auto p : known_primes) {
        for (uint64_t i = p; i <= max_prime; i += p) {
            sieve[i] = 1;
        }
    }
    uint64_t temp_idx = known_primes.back();

    while (true) {
        while (temp_idx <= max_prime && sieve[++temp_idx]) {}
        if (temp_idx > max_prime) break;
        for (uint64_t i = temp_idx; i <= max_prime; i += temp_idx) {
            sieve[i] = 1;
        }
        known_primes.push_back(temp_idx);
    }
}

uint64_t PrimeIterator::operator*() const {
    return known_primes[idx];
}

PrimeIterator& PrimeIterator::operator++() {
    if (idx == known_primes.size() - 1) {
        int64_t num = known_primes[idx] + 1;
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
