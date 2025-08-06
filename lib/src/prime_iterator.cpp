#include <vector>
#include "prime.h"

using std::vector;

static vector<int> sieve;

PrimeIterator::PrimeIterator():idx(0) {}

PrimeIterator::PrimeIterator(uint64_t max_prime):idx(0) {
    if (max_prime + 1 > sieve.size()) {
        sieve.resize(max_prime + 1, 0);
    }
    for (auto p : PrimeIterator::known_primes) {
        for (uint64_t i = p; i <= max_prime; i += p) {
            sieve[i] = 1;
        }
    }
    uint64_t temp_idx = PrimeIterator::known_primes.back();

    while (true) {
        while (temp_idx <= max_prime && sieve[++temp_idx]) {}
        if (temp_idx > max_prime) break;
        for (uint64_t i = temp_idx; i <= max_prime; i += temp_idx) {
            sieve[i] = 1;
        }
        PrimeIterator::known_primes.push_back(temp_idx);
    }
}
