#include <iostream>
#include <cassert>
#include "number_theory.h"

using namespace std;

int main () {
    Polynomial<Int128> p({1,-1,1,-1,1,-1,1,-1,1,-1,1});
    // Polynomial<Int128> p({1,1,1,1,1,1,1,1,1,1,1});
    // Polynomial<Int128> p({0,0,0,1});

    // seq
    vector<Int128> out;
    for (Int128 n = 1; n <= p.degree(); n = n + 1) {
        out.push_back(p(n));
    }

    Int128 bops = 0;
    for (size_t i = 0; i < out.size(); i++) {
        vector<pair<Int128, Int128>> b;
        for (size_t j = 0; j <= i; j++) {
            b.push_back({j + 1, out[j]});
        }
        Polynomial<Frac<Int128>> op = lagrange_interpolation(b);
        Int128 test_num = 1;
        while (op(test_num) == p(test_num)) {
            test_num = test_num + 1;
        }
        bops = bops + op(test_num).num;
    }
    assert(bops == 37076114526);

    return 0;
}
