#include "prime.h"
#include <iostream>
#include <cassert>
#include <set>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    set<unsigned int> covered;

    static const unsigned int MAX_NUM = 12000;
    unsigned int k = 4;
    unsigned int grand_sum = 0;
    while (covered.size() != MAX_NUM - 1) {
        bool found = false;
        for (FactorizationIterator fit(k); !fit.end(); ++fit) {
            unsigned int sum = 0;
            for (unsigned int x : *fit) {
                sum += x;
            }
            if (sum > k) continue;
            unsigned int new_total = k - sum + (*fit).size();
            if (new_total > MAX_NUM || new_total < 2) continue;
            if (covered.contains(new_total)) continue;

            covered.insert(new_total);
            found = true;
        }
        if (found) {
            grand_sum += k;
        }
        k++;
    }
    assert(grand_sum == 7587457);

    return 0;
}
