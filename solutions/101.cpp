#include <iostream>
#include <cassert>
#include "number_theory.h"

using namespace std;

int main () {
    Polynomial<__int128_t> p({1,-1,1,-1,1,-1,1,-1,1,-1,1});
    // Polynomial<__int128_t> p({1,1,1,1,1,1,1,1,1,1,1});
    // Polynomial<__int128_t> p({0,0,0,1});

    // seq
    vector<__int128_t> out;
    for (__int128_t n = 1; n <= p.degree(); n = n + 1) {
        out.push_back(p(n));
    }

    __int128_t bops = 0;
    for (size_t i = 0; i < out.size(); i++) {
        vector<pair<__int128_t, __int128_t>> b;
        for (size_t j = 0; j <= i; j++) {
            b.push_back({j + 1, out[j]});
        }
        Polynomial<Frac<__int128_t>> op = lagrange_interpolation(b);
        __int128_t test_num = 1;
        while (op(test_num) == p(test_num)) {
            test_num = test_num + 1;
        }
        bops = bops + op(test_num).num;
    }
    assert(bops == 37076114526);

    return 0;
}
