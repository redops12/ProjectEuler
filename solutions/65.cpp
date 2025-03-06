#include <vector>
#include "number_theory.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char * argv[]) {
    vector<int> terms;
    terms.push_back(2);
    for (int i = 0; i < 100; i++) {
        switch (i % 3) {
            case 0:
                terms.push_back(1);
                break;
            case 1:
                terms.push_back(2 * ((i / 3) + 1));
                break;
            case 2:
                terms.push_back(1);
                break;
        }
    }
    ContinuedFrac cf(terms);
    auto p = cf.convergent();
    cpp_int x = p.second;
    int sum = 0;
    while (x != 0) {
        cpp_int residue = x % 10;
        sum += (int) residue;
        x /= 10;
    }
    assert(sum == 272);
}
