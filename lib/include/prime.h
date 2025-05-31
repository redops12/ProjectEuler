#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include <deque>
#include "sqrt.h"

class PrimeIterator {
private:
    size_t idx;
public:
    PrimeIterator();
    PrimeIterator(uint64_t max);
    uint64_t operator*() const;
    PrimeIterator& operator++();
    bool operator!=(const PrimeIterator& other) const;
    PrimeIterator operator+(int offset);
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
