#include "combinatorics.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "macros.h"

using namespace std;
using namespace boost::multiprecision;

int main(int argc, char * argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    cpp_int test = 1;
    for (int i = 0; i < 50; i++) {
        cpp_int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += n_choose_r(i, j);
        }
        assert(sum == test);
        test *= 2;
    }
    assert(n_choose_r(40,20) == 137846528820);
}
