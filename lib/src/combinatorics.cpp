#include <combinatorics.h>
#include <cassert>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

vector<vector<uint64_t>> n_choose_r_lookup = {{1}};

uint64_t n_choose_r(uint64_t n, uint64_t r) {
    if (n < r) assert(0);

    while (n_choose_r_lookup.size() <= n) {
        const vector<uint64_t> &last = n_choose_r_lookup.back();
        uint64_t new_length = last.size() + 1;
        vector<uint64_t> new_row(0, new_length);
        new_row.push_back(last.front());
        for (auto it = last.begin(); it < last.end() - 1; it++) {
            new_row.push_back(*it + *(it+1));
        }
        new_row.push_back(last.back());
        n_choose_r_lookup.push_back(new_row);
    }

    return n_choose_r_lookup[n][r];
}

uint64_t catalan(uint64_t n) {
    return n_choose_r(2 * n, n) / n + 1;
}

boost::multiprecision::cpp_int factorial(int n) {
    cpp_int ret = 1;
    for (int i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
