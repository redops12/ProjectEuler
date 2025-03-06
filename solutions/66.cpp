#include <iostream>
#include <cstdint>
#include <cmath>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "prime.h"
#include "number_theory.h"

using namespace std;
using namespace boost::multiprecision;

int main(int argc, char * argv[]) {
    cpp_int max_x = 0;
    int max_d;
    for (int D = 2; D <= 1000; D++) {
        if (fast_is_square(D)) continue;
        ContinuedFrac cf(D);
        auto p = cf.convergent();
        cpp_int x;
        if (cf.repeated.size() % 2 == 0) {
            x = p.first;
        } else {
            x = p.first * p.first + D * p.second * p.second;
        }
        if (x > max_x) {
            max_d = D;
            max_x = x;
        }
    }
    assert(max_d == 661);
}
