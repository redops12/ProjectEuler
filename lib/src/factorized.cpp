#include "prime.h"

Factorized::Factorized(int num) {
    PrimeIterator it;
    if (num == 0) return;
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

bool Factorized::square_free() {
    for (auto p : factors) {
        if (p.second > 1) {
            return false;
        }
    }
    return true;
}

bool Factorized::operator<(const Factorized &rhs) const {
    auto pair = factors.begin();
    auto pair_rhs = rhs.factors.begin();
    while (pair != factors.end() && pair_rhs != rhs.factors.end()) {
        if (pair->first < pair_rhs->first) return true;
        if (pair->first > pair_rhs->first) return false;
        if (pair->second < pair_rhs->second) return true;
        if (pair->second > pair_rhs->second) return false;
        pair++;
        pair_rhs++;
    }
    if (pair == factors.end() && pair_rhs == rhs.factors.end()) return false;
    if (pair == factors.end()) return true;
    if (pair_rhs == rhs.factors.end()) return false;
    return true;
}

void Factorized::power_of(int num) {
    for (auto &p : factors) {
        p.second *= num;
    }
}
