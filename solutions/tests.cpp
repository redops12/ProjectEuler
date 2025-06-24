#include "combinatorics.h"
#include <cassert>
#include "prime.h"
#include "number_theory.h"
#include "macros.h"
#include <boost/multiprecision/cpp_int.hpp>

using big_int = boost::multiprecision::number<
    boost::multiprecision::cpp_int_backend<>,
    boost::multiprecision::et_off>;

void general_pent_tests() {
    GeneralizedPentagonal git;
    assert(*git == 1);
    ++git;
    assert(*git == 2);
    ++git;
    assert(*git == 5);
    ++git;
    assert(*git == 7);
}

void n_choose_r_tests() {
    __uint128_t test = 1;
    for (int i = 0; i < 50; i++) {
        __uint128_t sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += n_choose_r(i, j);
        }
        assert(sum == test);
        test *= 2;
    }
}

void is_square_tests() {
    assert(fast_is_square(4));
    assert(!fast_is_square(5));
    assert(fast_is_square(16384));
    assert(fast_is_square(100));
    assert(!fast_is_square(99));
    assert(!fast_is_square(63));
    assert(!fast_is_square(65));
    auto str = std::string("100000000000000");
    big_int x = big_int(str);
    assert(fast_is_square(x));
}

void primes_tests() {
    PrimeIterator pit(10000);
    for (unsigned int i = 2; i < 10000; i++) {
        bool prime = true;
        for (unsigned int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            assert(*pit == i);
            ++pit;
        }
    }
    assert(is_prime(100000007) == true);
}

void factorized_tests() {
    Factorized f1(2);
    assert(!f1.is_square());
    assert(!fast_is_square(2));
    Factorized f2(4);
    assert(f2.is_square());
    assert(fast_is_square(4));
    Factorized f3(6);
    assert(!f3.is_square());
    assert(!fast_is_square(6));
    Factorized f4(36);
    assert(f4.is_square());
    assert(fast_is_square(36));
}

void ContinuedFrac_tests() {
    ContinuedFrac c23(23);
    assert(c23.initial == 4);
    assert(c23.repeated[0] == 1);
    assert(c23.repeated[1] == 3);
    assert(c23.repeated[2] == 1);
    assert(c23.repeated[3] == 8);
    ContinuedFrac c2(2);
    assert(c2.repeated.size() == 1);
    ContinuedFrac c3(3);
    assert(c3.repeated.size() == 2);
    ContinuedFrac c5(5);
    assert(c5.repeated.size() == 1);
    ContinuedFrac c6(6);
    assert(c6.repeated.size() == 2);
}

void mobius_tests() {
    int max_mobius = 10000;
    Mobius m(max_mobius);
    for (int i = 1; i < max_mobius; i++) {
        assert(m.at(i) == slow_mobius(i));
    }
}

void totient_tests() {
    int max_totient = 5000;
    Totient t(max_totient);
    for (int i = 1; i < max_totient; i++) {
        assert(t.at(i) == slow_totient(i));
    }
}

void factorization_iterator_tests() {
    std::vector<std::vector<unsigned int>> sols = {
        {12},
        {3, 4},
        {2, 6},
        {2, 2, 3}
    };
    size_t i = 0;
    for (FactorizationIterator fit(12); !fit.end(); ++fit, ++i) {
        assert(*fit == sols[i]);
    }
}

int main(int argc, char * argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    general_pent_tests();
    n_choose_r_tests();
    is_square_tests();
    primes_tests();
    factorized_tests();
    ContinuedFrac_tests();
    mobius_tests();
    totient_tests();
    factorization_iterator_tests();
}
