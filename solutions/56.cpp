#include "strint.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {

    int max_dig_sum = 0;
    for (cpp_int i = 1; i < 100; i++) {
        for (int j = 1; j < 100; j++) {
            cpp_int power = boost::multiprecision::pow(i, j);
            int sum = 0;
            for (DigIterator it(power); it != it.end(); ++it) {
                sum += *it;
            }
            max_dig_sum = max(sum, max_dig_sum);
        }
    }
    cout << max_dig_sum << endl;

    return 0;
}
