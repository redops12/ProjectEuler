#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

uint64_t concat(uint64_t l, uint64_t r);
uint64_t base_10(uint64_t num);
int sum_digits(boost::multiprecision::cpp_int x);

template <class T>
class DigIterator {
private:
    T num;
public:
    DigIterator(T num);
    int operator*() const;
    DigIterator& operator++();
    bool operator!=(const DigIterator& other) const;
    bool done() const;
};

// include template definitions
#include "strint.tpp"
