#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char * argv[]) {
    cpp_int x = 1;
    for (int i = 0; i < 1000; i++) {
        x *= 2;
    }
    int sum = 0;
    cout << x << endl;
    while (x != 0) {
        cpp_int residue = x % 10;
        sum += (int) residue;
        x /= 10;
    }
    cout << sum << endl;
}
