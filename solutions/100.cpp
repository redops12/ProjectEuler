#include "prime.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "macros.h"

using namespace std;
using boost::multiprecision::cpp_int;

typedef __uint128_t NUM;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    // NUM m = 292893218819;
    NUM m = 1;
    NUM sqrt_exp = sqrt(m * m * 8 + 1);

    while (true)  {
        sqrt_exp += 2;
        if (fast_is_square((sqrt_exp * sqrt_exp - 1)/8)) {
            m = sqrt((sqrt_exp * sqrt_exp - 1)/8);
            NUM n = (1 + 2 * m + sqrt_exp) / 2;
            cout << log10(n + m) << " " << static_cast<uint64_t>(n) << " " << static_cast<uint64_t>(m) << " " << static_cast<float>(((m + n) * (m + n - 1))) / static_cast<float>((n * (n - 1))) << endl;
        }
    }
    return 0;
}
