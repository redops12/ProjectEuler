#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <iterator>

uint64_t concat(uint64_t l, uint64_t r);
uint64_t concat(const std::vector<int> &v);
uint64_t base_10(uint64_t num);
int log_10(uint64_t num);
int sum_digits(boost::multiprecision::cpp_int x);

template <class T>
std::vector<int> get_digits(T x);

template <class T>
class DigIterator {
private:
    T num;
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    DigIterator(T num);
    int operator*() const;
    DigIterator& operator++();
    bool operator!=(const DigIterator& other) const;
    bool operator==(const DigIterator& other) const;
    DigIterator end();
};

// include template definitions
#include "strint.tpp"
