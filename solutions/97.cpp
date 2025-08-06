#include <iostream>
#include <cassert>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    cpp_int p = 10000000000;
    int mask = 7830457;
    int mult = 28433;
    cpp_int base = 2;
    int power = 0;
    cpp_int num = 1;
    while (1 << power < mask) {
        if ((mask & (1 << power)) != 0) {
            num *= base;
            num %= p;
        }
        base *= base;
        base %= p;
        power++;
    }
    num *= mult;
    num %= p;
    num++;
    cout << num << endl;

    return 0;
}
