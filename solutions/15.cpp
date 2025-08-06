#include "combinatorics.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    assert(n_choose_r(40,20) == 137846528820);
}
