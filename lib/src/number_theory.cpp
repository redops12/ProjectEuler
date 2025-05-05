#include <cmath>
#include <set>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "number_theory.h"
#include "prime.h"

using namespace std;
using namespace boost::multiprecision;

ExtendedEuclidean::ExtendedEuclidean(int64_t a, int64_t b) {
    int64_t s = 0;
    int64_t old_s = 1;
    int64_t t = 1;
    int64_t old_t = 0;
    int64_t r = b;
    int64_t old_r = a;
    while (r != 0) {
        int64_t div = old_r / r;
        int64_t temp = old_r - div * r;
        old_r = r;
        r = temp;
        temp = old_s - div * s;
        old_s = s;
        s = temp;
        temp = old_t - div * t;
        old_t = t;
        t = temp;
    }
    g = old_r;
    x = old_s;
    y = old_t;
    assert(a * x + b * y == g);
}

uint64_t inverse_mod_p(uint64_t n, uint64_t p) {
    ExtendedEuclidean ex(n, p);
    return (ex.x + p) % p;
}

RadicalRational::RadicalRational(int c) {
    this->a = 0;
    this->b = 1;
    this->c = c;
    this->sqrt_c = std::sqrt(c);
    this->d = 1;
}

void RadicalRational::invert() {
    RadicalRational inv = *this;
    this->c = inv.c;
    this->sqrt_c = inv.sqrt_c;
    this->a = inv.d * inv.a;
    this->b = inv.d * -1 * inv.b;
    this->d = inv.a * inv.a - inv.b * inv.b * inv.c;
    reduce();
}

void RadicalRational::reduce() {
    int temp_gcd = gcd(a, b);
    temp_gcd = gcd(temp_gcd, d);

    int neg = (d < 0) ? -1 : 1;
    this->a /= temp_gcd * neg;
    this->b /= temp_gcd * neg;
    this->d /= temp_gcd * neg;
}

float RadicalRational::to_float() {
    return (static_cast<float>(a) + (static_cast<float>(b) * sqrt_c)) / static_cast<float>(d);
}

inline bool RadicalRational::operator<(const RadicalRational &rhs) const {
    return a < rhs.a || b < rhs.b || c < rhs.c || d < rhs.d;
}

inline bool RadicalRational::operator==(const RadicalRational &rhs) const {
    return a == rhs.a &&
        b == rhs.b &&
        c == rhs.c &&
        d == rhs.d;
}

void RadicalRational::sub(int right) {
    this->a -= right * d;
    reduce();
};

ContinuedFrac::ContinuedFrac(int c) {
    RadicalRational r(c);
    this->initial = floor(r.to_float());
    r.sub(this->initial);
    RadicalRational repeated_r = r;
    do {
        RadicalRational new_r = r;
        new_r.invert();
        int res = floor(new_r.to_float());
        repeated.push_back(res);
        new_r.sub(res);
        r = new_r;
    } while (!(r == repeated_r));
}

ContinuedFrac::ContinuedFrac(vector<int> v) {
    repeated = v;
}

std::pair<cpp_int, cpp_int> ContinuedFrac::convergent() {
    cpp_int num = 0, denom = 1;
    for (auto it = repeated.rbegin() + 1; it != repeated.rend(); ++it) {
        num += *it * denom;
        swap(num, denom);
        cpp_int g = gcd(num, denom);
        num /= g;
        denom /= g;
    }
    return make_pair(num, denom);
}

Mobius::Mobius(uint64_t max) {
    mobius_val.resize(max + 1, 1);
    for (PrimeIterator it(max); *it < max; ++it) {
        for (unsigned int i = 0; i < mobius_val.size(); i += *it) {
            if (i < (1 << 30) / *it && i * *it < mobius_val.size()) {
                mobius_val[i * *it] = 0;
            }
            mobius_val[i] *= -1;
        }
    }
}

int Mobius::at(uint64_t idx) {
    return mobius_val[idx];
}

int8_t slow_mobius(uint64_t x) {
    Factorized f(x);
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (!f.square_free()) return 0;
    return (f.factors.size() % 2) ? -1 : 1;
}

Totient::Totient(unsigned int max) {
    totient_val.resize(max + 1);
    totient_val[0] = 1;
    for (uint64_t i = 1; i < max; i++) {
        totient_val[i] = i;
    }
    for (PrimeIterator it(max); *it < max; ++it) {
        for (size_t i = *it; i < totient_val.size(); i += *it) {
            totient_val[i] -= totient_val[i] / *it;
        }
    }
}

unsigned int Totient::at(unsigned int idx) {
    return totient_val[idx];
}

uint64_t slow_totient(uint64_t x) {
    if (x == 0 || x == 1) return 1;
    uint64_t count = 0;
    for (uint64_t i = 1; i < x; i++) {
        if (gcd(i, x) == 1) {
            count++;
        }
    }
    return count;
}

std::vector<unsigned int> get_coprime(unsigned int num) {
    vector<unsigned int> coprimes;
    vector<unsigned int> filter(num, 0);
    for (PrimeIterator pit; *pit < num; ++pit) {
        if (num % *pit == 0) {
            for (size_t i = *pit; i < filter.size(); i += *pit) {
                filter[i] = 1;
            }
        }
    }
    for (size_t i = 1; i < filter.size(); i++) {
        if (filter[i] == 0) {
            coprimes.push_back(i);
        }
    }
    return coprimes;
}

static vector<cpp_int> part = {1};
cpp_int partition(uint32_t n) {
    for (int i = part.size(); static_cast<uint32_t>(i) <= n; i++) {
        int mult = 1;
        part.push_back(0);
        for (int k = 1; i - (k * ( 3 * k - 1) / 2) >= 0; k++) {
            if (i - (k * ( 3 * k - 1) / 2) >= 0) {
                part[i] += mult * part[i - (k * ( 3 * k - 1) / 2)];
            }
            if (i - (k * ( 3 * k + 1) / 2) >= 0) {
                part[i] += mult * part[i - (k * ( 3 * k + 1) / 2)];
            }
            mult *= -1;
        }
    }
    return part.back();
}
