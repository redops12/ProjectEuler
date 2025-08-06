#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using big_int = boost::multiprecision::number<
    boost::multiprecision::cpp_int_backend<>,
    boost::multiprecision::et_off>;

int main() {
    big_int num1 = 1;
    big_int num2 = 1;
    int idx = 2;
    big_int comparator = 1;
    for (int i = 0; i < 999; i++) {
        comparator *= 10;
    }
    while (true) {
        if (num2 > comparator) {
            cout << idx << endl;
            break;
        }
        big_int temp = num1 + num2;
        num1 = num2;
        num2 = temp;
        idx++;
    }
}
