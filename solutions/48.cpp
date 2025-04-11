#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "macros.h"

using namespace std;
using namespace boost::multiprecision;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    cpp_int modulo = pow(cpp_int(10), 10);
    cout << modulo << endl;
    cpp_int out = 0;
    for (int i = 1; i <= 1000; i++) {
        out += pow(cpp_int(i), i) % modulo;
    }
    cout << out % modulo << endl;

    return 0;
}
