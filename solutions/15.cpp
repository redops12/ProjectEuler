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

    assert(n_choose_r(40,20) == 137846528820);
}
