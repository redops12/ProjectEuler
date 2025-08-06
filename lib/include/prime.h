#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include <deque>
#include "sqrt.h"

bool is_prime(int64_t num);
template <class T>
bool fast_is_square(T num) {
    switch (static_cast<uint16_t>(num % 128)) {
        case 0:
        case 1:
        case 4:
        case 9:
        case 16:
        case 17:
        case 25:
        case 33:
        case 36:
        case 41:
        case 49:
        case 57:
        case 64:
        case 65:
        case 68:
        case 73:
        case 81:
        case 89:
        case 97:
        case 100:
        case 105:
        case 113:
        case 121:
            {
                T temp = typed_sqrt(num);
                return temp * temp == num;
                break;
            }
        default:
            return false;
    }
}

class PrimeIterator {
private:
    size_t idx;
public:
    static inline std::vector<uint64_t> known_primes = {2};
    PrimeIterator();
    PrimeIterator(uint64_t max);
    inline uint64_t operator*() const {
        return PrimeIterator::known_primes[idx];
    }

    inline PrimeIterator& operator++() {
        if (idx == PrimeIterator::known_primes.size() - 1) {
            int64_t num = PrimeIterator::known_primes[idx] + 1;
            while (true)
            {
                if (is_prime(num)) {
                    PrimeIterator::known_primes.push_back(num);
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

    inline bool operator!=(const PrimeIterator& other) const {
        return this->idx != other.idx;
    }

    inline PrimeIterator operator+(int offset) {
        PrimeIterator prime_copy = *this;
        for (int i = 0; i < offset; i++) {
            ++prime_copy;
        }
        return prime_copy;
    }

    static void extend(uint64_t upper_bound);
};

class Factorized {
public:
    Factorized(int num);
    std::map<int, int> factors;
    int num_divisors();
    bool is_square();
    bool square_free();
    void power_of(int num);

    // this operator does not actually measure less
    bool operator<(const Factorized &rhs) const;
};

class FactorizationIterator {
private:
    class DFS {
        public:
        std::vector<uint32_t> current;
        uint32_t max_div;
        uint64_t number;
    };
    std::deque<DFS> queue;
    std::vector<uint32_t> expansion;
    bool done;
public:
    FactorizationIterator(uint32_t num);
    std::vector<uint32_t> operator*() const;
    FactorizationIterator& operator++();
    bool end();
};

