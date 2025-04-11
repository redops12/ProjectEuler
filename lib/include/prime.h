#include <cstdint>
#include <map>

class PrimeIterator {
private:
    size_t idx;
public:
    PrimeIterator();
    PrimeIterator(uint64_t max);
    unsigned int operator*() const;
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

bool is_prime(int64_t num);
bool fast_is_square(uint64_t num);
