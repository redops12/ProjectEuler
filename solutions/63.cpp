#include "strint.h"
#include <iostream>
#include <cassert>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main (int argc, char *argv[]) {
    set<cpp_int> uniq = {};
    for (cpp_int i = 1; i < 10; i++) {
        cpp_int base = i;
        cpp_int prev = -1;
        for (int j = 0; ;j++) {
            if (prev == base) {
                break;
            }
            int b = log_10(base);
            if (b == j) {
                uniq.insert(base);
            } else if (b + 5 < j) {
                break;
            }
            prev = base;
            base *= i;
        }
    }
    assert(uniq.size() == 49);

    return 0;
}
