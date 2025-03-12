#include <cstdint>
#include <vector>
#include "strint.h"

using namespace boost::multiprecision;
using namespace std;

uint64_t base_10(uint64_t num) {
    uint64_t base;
    for (base = 10; base < num; base *= 10) {}
    return base;
}

int log_10(uint64_t num) {
    uint64_t base;
    int log = 0;
    for (base = 10; base < num; base *= 10) {
        log++;
    }
    return log;
}

uint64_t concat(const vector<int> &v) {
    uint64_t num = 0;
    for (int x : v) {
        assert(x >= 0 && x < 10);
        num *= 10;
        num += x;
    }
    return num;
}

uint64_t concat(uint64_t l, uint64_t r) {
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
