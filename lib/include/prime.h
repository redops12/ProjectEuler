#include <vector>
#include <cstdint>

using std::vector;

class PrimeIterator {
private:
    size_t idx;
public:
    PrimeIterator();
    int operator*() const;
    PrimeIterator& operator++();
    bool operator!=(const PrimeIterator& other) const;
    PrimeIterator operator+(int offset);
};

bool is_prime(uint64_t num);
