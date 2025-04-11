#include <cstdint>
#include <vector>
#include <iterator>
#include "strint.h"

using namespace boost::multiprecision;
using namespace std;

uint64_t base_10(uint64_t num) {
    uint64_t base;
    for (base = 10; base < num; base *= 10) {}
    return base;
}

uint64_t concat_num(uint64_t l, uint64_t r) {
    uint64_t mult = base_10(r);
    uint64_t ret = mult * l + r;
    return ret;
}

int sum_digits(boost::multiprecision::cpp_int x) {
    int sum = 0;
    while (x != 0) {
        boost::multiprecision::cpp_int residue = x % 10;
        sum += (int) residue;
        x /= 10;
    }
    return sum;
}

bool is_palindrome(const std::vector<int> &v) {
    auto rit = v.rbegin();
    for (auto it = v.begin(); it < v.begin() + v.size() / 2; ++it, ++rit) {
        if (*it != *rit) return false;
    }
    return true;
}

bool is_pandigital(const uint64_t x, size_t n) {
    vector<unsigned int> digits = get_digits(x);
    if (digits.size() != n) return false;
    sort(digits.begin(), digits.end());
    for (unsigned int i = 0; i < n; i++) {
        if (digits[i] != i+1) return false;
    }
    return true;
}
