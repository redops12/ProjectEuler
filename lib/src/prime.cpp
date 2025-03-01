#include <vector>
#include "functions.h"
#include "prime.h"

using std::vector;

static vector<int> known_primes = {2};

PrimeIterator::PrimeIterator():current_prime(known_primes.begin()) {}

/**
 * @brief Get an iterator to the first prime number greater than start
 */
PrimeIterator::PrimeIterator(int start) {
    current_prime = binary_search(known_primes, start);
    if (current_prime == known_primes.end()) {
        current_prime = known_primes.begin();
    }
}

int PrimeIterator::operator*() const {
    return *current_prime;
}

PrimeIterator& PrimeIterator::operator++() {
    if (current_prime == known_primes.end()) {
        int num = *current_prime + 1;
        while (true)
        {
            bool prime = true;
            for (auto p : known_primes) {
                if (num % p == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                known_primes.push_back(num);
                break;
            }
        }
        num++;
    }
    current_prime++;
    return *this;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return this->current_prime != other.current_prime;
}
