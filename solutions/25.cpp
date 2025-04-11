#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include "macros.h"

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char * argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    cpp_int num1 = 1;
    cpp_int num2 = 1;
    int idx = 2;
    cpp_int comparator = 1;
    for (int i = 0; i < 999; i++) {
        comparator *= 10;
    }
    while (true) {
        if (num2 > comparator) {
            cout << idx << endl;
            break;
        }
        cpp_int temp = num1 + num2;
        num1 = num2;
        num2 = temp;
        idx++;
    }
}
