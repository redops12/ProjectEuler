#include "number_theory.h"
#include "strint.h"
#include <iostream>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

int main() {

    static const uint64_t MAX = 10000000;
    Totient tfn(MAX);
    vector<pair<uint64_t,uint64_t>> perms;
    for (unsigned int i = 2; i < MAX; i++) {
        if (is_perm(i, tfn.at(i))) {
            perms.push_back(make_pair(i, tfn.at(i)));
        }
    }
    pair<uint64_t, uint64_t> min_pair(10000,1);
    for (auto p : perms) {
        // a1/a2 < b1/b2
        if (min_pair.first * p.second > min_pair.second * p.first) {
            min_pair = p;
        }
    }
    cout << min_pair.first << endl;
    return 0;
}
