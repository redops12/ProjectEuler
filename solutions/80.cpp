#include "strint.h"
#include "prime.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include "macros.h"

using namespace std;
using namespace boost::multiprecision;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    uint64_t total = 0;
    for (unsigned int i = 1; i <= 100; i++) {
        if (fast_is_square(i)) {
            continue;
        }
        cpp_int num = 10;
        num = i * pow(num, 198);
        cpp_int lb = 0;
        cpp_int ub = num;
        while (lb + 1 < ub) {
            cpp_int mp = (lb + ub) / 2;
            if (mp * mp > num) {
                ub = mp;
            }
            if (mp * mp <= num) {
                lb = mp;
            }
        }
        cout << lb << endl;
        for (DigIterator dit(lb); dit != dit.end(); ++dit) {
            total += *dit;
        }
    }
    cout << total << endl;

    return 0;
}
