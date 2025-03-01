#include <cstdint>

uint64_t base_10(uint64_t num) {
    uint64_t base;
    for (base = 10; base < num; base *= 10) {}
    return base;
}

uint64_t concat(uint64_t l, uint64_t r) {
    uint64_t mult = base_10(r);
    uint64_t ret = mult * l + r;
    return ret;
}
