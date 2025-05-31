#include <vector>
#include "prime.h"
#include <algorithm>
#include <boost/dynamic_bitset.hpp>

using std::vector;
using std::binary_search;
using std::copy;

extern vector<uint64_t> known_primes;

bool is_prime(int64_t num) {
    uint64_t unsigned_num = (num < 0) ? num * -1 : num;
    if (unsigned_num == 0 || unsigned_num == 1) return false;
    if (unsigned_num < known_primes.back()) {
        return binary_search(known_primes.begin(), known_primes.end(), unsigned_num);
    }
    if (static_cast<uint64_t>(known_primes.back()) * known_primes.back() < unsigned_num) {
        PrimeIterator p;
        while ((*p) * (*p) < unsigned_num) {
            ++p;
        }
    }
    for (auto p : known_primes) {
        if (p * p > unsigned_num) {
            break;
        }
        if (unsigned_num % p == 0) {
            return false;
            break;
        }
    }
    return true;
}
