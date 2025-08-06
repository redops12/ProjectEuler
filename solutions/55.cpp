#include "strint.h"
#include <iostream>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using namespace std;
using namespace boost::multiprecision;

int main() {

    int count = 0;
    for (size_t i = 0; i < 10000; i++) {
        vector<unsigned int> digs = get_digits(i);
        bool lychrel = true;
        for (size_t j = 0; j < 50; j++) {
            cpp_int sum = concat_big(digs.begin(), digs.end()) + concat_big(digs.rbegin(), digs.rend());
            digs = get_digits(sum);
            if (is_palindrome(digs)) {
                lychrel = false;
                break;
            }
        }
        if (lychrel) {
            count++;
        }
    }
    assert(count == 249);

    return 0;
}
