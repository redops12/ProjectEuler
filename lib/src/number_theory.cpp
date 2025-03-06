#include <cmath>
#include <set>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "number_theory.h"

using namespace std;
using namespace boost::multiprecision;

template <class T>
T gcd(T a, T b) {
    a = abs(a);
    b = abs(b);
    if (a < b) {
        swap(a, b);
    }
    while (true) {
        if (b == 0)
            return a;
        T r = a % b;
        a = b;
        b = r;
    }
}

RadicalRational::RadicalRational(int c) {
    this->a = 0;
    this->b = 1;
    this->c = c;
    this->sqrt_c = std::sqrt(c);
    this->d = 1;
}

RadicalRational::RadicalRational(const RadicalRational &copy) {
    this->c = copy.c;
    this->sqrt_c = copy.sqrt_c;
    this->a = copy.a;
    this->b = copy.b;
    this->d = copy.d;
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
