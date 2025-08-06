#include "number_theory.h"
#include "strint.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {

    vector<int> terms;
    terms.push_back(1);
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        terms.push_back(2);
        ContinuedFrac cf(terms);
        auto p = cf.convergent();
        if (log_10(p.second) > log_10(p.first)) {
            count++;
        }
    }
    assert(count == 153);
    return 0;
}
