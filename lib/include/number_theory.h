#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

template <class T>
T gcd(T a, T b);

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
    RadicalRational(const RadicalRational &copy);
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

// include template definitions
#include "number_theory.tpp"
