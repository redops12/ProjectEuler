#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include "strint.h"

template <class T>
T gcd(T a, T b);

class ExtendedEuclidean{
    public:
    // ax + by = g
    int64_t g;
    int64_t x;
    int64_t y;
    ExtendedEuclidean(int64_t a, int64_t b);
};

uint64_t inverse_mod_p(uint64_t n, uint64_t p);

template <class T>
class Frac {
public:
    T num;
    T denom;
    Frac(T num, T denom);
    Frac(T num);
    bool operator==(const Frac& other) const;
    bool operator<(const Frac& other) const;
    Frac<T> operator*(const Frac& rhs) const;
    Frac<T> operator+(const Frac& rhs) const;
    Frac<T> operator-(const Frac& rhs) const;
    Frac<T> operator/(const Frac& rhs) const;
    operator std::string() const;
    void reduce();
};

std::vector<unsigned int> get_coprime(unsigned int num);

class RadicalRational {
    // Expression of form
    //
    // a + b * sqrt(c)
    // ---------------
    //      d
    //
    int a;
    int b;
    int c;
    float sqrt_c;
    int d;

    public:
    // Create simple
    //
    //  sqrt(c)
    //
    RadicalRational(int c);

    // Create this number from opposite reciprocal
    //
    //       d
    // ---------------
    // a + b * sqrt(c)
    //
    void invert();
    void reduce();
    float to_float();
    inline bool operator<(const RadicalRational &rhs) const;
    inline bool operator==(const RadicalRational &rhs) const;
    void sub(int right);
};

class ContinuedFrac {
    public:
    int initial;
    std::vector<int> repeated;

    // Generate continued_frac from sqrt
    ContinuedFrac(int c);
    ContinuedFrac(std::vector<int> v);
    std::pair<boost::multiprecision::cpp_int, boost::multiprecision::cpp_int> convergent();
};

class Mobius {
    uint64_t max;
    std::vector<int> mobius_val;
public:
    Mobius(uint64_t max);
    int at(uint64_t idx);
};

int8_t slow_mobius(uint64_t x);

class Totient {
    unsigned int max;
    std::vector<uint64_t> totient_val;
public:
    Totient(unsigned int max);
    unsigned int at(unsigned int idx);
};

uint64_t slow_totient(uint64_t x);

class GeneralizedPentagonal {
    int prev;
    bool parity;
    unsigned int curr;
    public:
    inline GeneralizedPentagonal(): prev(1), parity(0), curr(1) {}
    inline GeneralizedPentagonal& operator++() {
        if (parity) {
            parity = false;
            curr = (3 * this->prev * this->prev - this->prev) >> 1;
        } else {
            parity = true;
            curr = (3 * this->prev * this->prev + this->prev) >> 1;
            prev++;
        }
        return *this;
    }

    inline unsigned int operator*() const {
        return curr;
    }
};

class DivisorSum {
    private:
    std::vector<unsigned int> lookup;
    public:
    DivisorSum(unsigned int max);
    unsigned int at(unsigned int val);
    unsigned int at_proper(unsigned int val);
};

template <class T>
class Polynomial {
    std::vector<T> coeffs;
    public:
    // constructors
    Polynomial(std::vector<T> coeffs);
    Polynomial(T constant);

    unsigned int degree() const;
    T evaluate(T x);
    T operator()(T x);
    Polynomial<T> operator*(const Polynomial<T>& rhs) const;
    Polynomial<T> operator+(const Polynomial<T>& rhs) const;
    Polynomial<T> operator-(const Polynomial<T>& rhs) const;
    Polynomial<T> operator/(const T& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Polynomial<T>& p) {
        for (size_t i = 0; i < p.coeffs.size(); i++) {
            os << static_cast<std::string>(p.coeffs[i]) << "x^" << i;
            if (i != p.coeffs.size() - 1) {
                os << " + ";
            }
        }

        return os;
    }
};

boost::multiprecision::cpp_int partition(uint32_t n);

template <class T>
T gcd(T a, T b) {
    if constexpr (std::is_signed<T>::value) {
        a = std::abs(a);
        b = std::abs(b);
    }
    if (a < b) {
        std::swap(a, b);
    }
    while (true) {
        if (b == 0)
            return a;
        T r = a % b;
        a = b;
        b = r;
    }
}

template <class T>
Frac<T>::Frac(T num, T denom): num(num), denom(denom) {}

template <class T>
Frac<T>::Frac(T num): num(num), denom(1) {}

template <class T>
bool Frac<T>::operator==(const Frac& other) const {
    return this->num * other.denom == this->denom * other.num;
}

template <class T>
bool Frac<T>::operator<(const Frac& other) const {
    return this->num * other.denom < this->denom * other.num;
}

template <class T>
Frac<T> Frac<T>::operator*(const Frac& rhs) const {
    auto f = Frac<T>(this->num * rhs.num, this->denom * rhs.denom);
    f.reduce();
    return f;
}

template <class T>
Frac<T> Frac<T>::operator/(const Frac& rhs) const {
    auto f = Frac<T>(this->num * rhs.denom, this->denom * rhs.num);
    f.reduce();
    return f;
}

template <class T>
Frac<T> Frac<T>::operator+(const Frac& rhs) const {
    auto f = Frac<T>(this->num * rhs.denom + rhs.num * this->denom, this->denom * rhs.denom);
    f.reduce();
    return f;
}

template <class T>
Frac<T> Frac<T>::operator-(const Frac& rhs) const {
    auto f = Frac<T>(this->num * rhs.denom - rhs.num * this->denom, this->denom * rhs.denom);
    f.reduce();
    return f;
}

template <class T>
Frac<T>::operator std::string() const {
    return to_string(num) + " / " + to_string(denom);
}

template <class T>
void Frac<T>::reduce() {
    T gcd_res = gcd<T>(this->num, this->denom);
    this->num   = this->num / gcd_res;
    this->denom = this->denom / gcd_res;
}

template <class T>
Polynomial<T>::Polynomial(std::vector<T> coeffs): coeffs(coeffs) {}

template <class T>
Polynomial<T>::Polynomial(T constant): coeffs({constant}) {}

template <class T>
T Polynomial<T>::evaluate(T x) {
    T res = coeffs[0];
    T mult = x;
    for (size_t i = 1; i < coeffs.size(); i++) {
        res = res + coeffs[i] * mult;
        mult = mult * x;
    }
    return res;
}

template <class T>
T Polynomial<T>::operator()(T x) {
    return this->evaluate(x);
}

template <class T>
unsigned int Polynomial<T>::degree() const {
    return coeffs.size() - 1;
}

template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& rhs) const {
    std::vector<T> new_coeffs(this->degree() + rhs.degree() + 1, T(0));
    for (size_t i = 0; i < this->coeffs.size(); i++) {
        for (size_t j = 0; j < rhs.coeffs.size(); j++) {
            new_coeffs[i + j] = new_coeffs[i + j] + this->coeffs[i] * rhs.coeffs[j];
        }
    }
    return Polynomial<T>(new_coeffs);
}

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& rhs) const {
    std::vector<T> new_coeffs(std::max(this->coeffs.size(), rhs.coeffs.size()), T(0));
    for (size_t i = 0; i < this->coeffs.size(); i++) {
        new_coeffs[i] = new_coeffs[i] + this->coeffs[i];
    }
    for (size_t i = 0; i < rhs.coeffs.size(); i++) {
        new_coeffs[i] = new_coeffs[i] + rhs.coeffs[i];
    }
    return Polynomial<T>(new_coeffs);
}

template <class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& rhs) const {
    std::vector<T> new_coeffs(std::max(this->coeffs.size(), rhs.coeffs.size()), T(0));
    for (size_t i = 0; i < this->coeffs.size(); i++) {
        new_coeffs[i] += this->coeffs[i];
    }
    for (size_t i = 0; i < rhs.coeffs.size(); i++) {
        new_coeffs[i] -= rhs.coeffs[i];
    }
    for (size_t i = 0; i < new_coeffs.size(); i++) {
        new_coeffs[i].reduce();
    }
    return Polynomial<T>(new_coeffs);
}

template <class T>
Polynomial<T> Polynomial<T>::operator/(const T& rhs) const {
    std::vector<T> new_coeffs(this->coeffs.size(), T(0));
    for (size_t i = 0; i < this->coeffs.size(); i++) {
        new_coeffs[i] = this->coeffs[i] / rhs;
        new_coeffs[i].reduce();
    }
    return Polynomial<T>(new_coeffs);
}

template <class T>
Polynomial<Frac<T>> lagrange_interpolation(std::vector<std::pair<T, T>> points) {
    Polynomial<Frac<T>> res({Frac<T>(0)});
    for (size_t i = 0; i < points.size(); i++) {
        Polynomial<Frac<T>> term({Frac<T>(1)});
        for (size_t j = 0; j < points.size(); j++) {
            if (i == j) continue;
            term = term * Polynomial<Frac<T>>({Frac<T>(-points[j].first), Frac<T>(1)}) / Frac<T>(points[i].first - points[j].first);
        }
        res = res + term * Frac<T>(points[i].second);
    }
    return res;
}
