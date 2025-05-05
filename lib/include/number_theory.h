#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

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
private:
    T num;
    T denom;
public:
    Frac(T num, T denom);
    bool operator==(const Frac& other) const;
    Frac<T> operator*(const Frac& rhs) const;
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

boost::multiprecision::cpp_int partition(uint32_t n);

// include template definitions
#include "number_theory.tpp"
