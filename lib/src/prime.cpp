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

Factorized::Factorized(int num) {
    PrimeIterator it;
    while (num != 1) {
        if (num % *it == 0) {
            this->factors[*it]++;
            num /= *it;
            it = PrimeIterator();
        } else {
            ++it;
        }
    }
}

int Factorized::num_divisors() {
    int divisors = 1;
    for (auto p : factors) {
        divisors *= p.second + 1;
    }
    return divisors;
}

bool Factorized::is_square() {
    for (auto p : factors) {
        if (p.second % 2 != 0) {
            return false;
        }
    }
    return true;
}

bool is_prime(int64_t num) {
    if (num < 0) num = num * -1;
    if (num == 0 || num == 1) return false;
    if (num < known_primes.back()) {
        return binary_search(known_primes.begin(), known_primes.end(), num);
    }
    if (static_cast<uint64_t>(known_primes.back()) * known_primes.back() < num) {
        PrimeIterator p;
        while ((*p) * (*p) < num) {
            ++p;
        }
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

bool fast_is_square(uint64_t num) {
    PrimeIterator it;
    while ((*it) * (*it) <= num) {
        if (num % *it == 0) {
            num /= *it;
            if (num % *it != 0) {
                return false;
            }
            num /= *it;
            it = PrimeIterator();
        } else {
            ++it;
        }
    }
    return num == 1;
}
