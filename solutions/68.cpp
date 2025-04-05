#include "strint.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main (int argc, char *argv[]) {
    vector<int> perm = {1,2,3,4,5,6,7,8,9,10};
    cpp_int max_start = 0;
    do {
        if (perm[0] > perm[3] ||
            perm[0] > perm[5] ||
            perm[0] > perm[7] ||
            perm[0] > perm[9]) {
            continue;
        }
        if (perm[0] + perm[1] + perm[2] == perm[2] + perm[3] + perm[4] &&
            perm[2] + perm[3] + perm[4] == perm[4] + perm[5] + perm[6] &&
            perm[4] + perm[5] + perm[6] == perm[6] + perm[7] + perm[8] &&
            perm[6] + perm[7] + perm[8] == perm[9] + perm[8] + perm[1] &&
            perm[9] + perm[8] + perm[1] == perm[0] + perm[1] + perm[2])
        {
            vector<int> digs = {
                perm[0], perm[1], perm[2],
                perm[3], perm[2], perm[4],
                perm[5], perm[4], perm[6],
                perm[7], perm[6], perm[8],
                perm[9], perm[8], perm[1]};
            cpp_int curr = concat_big(digs.begin(), digs.end());
            if (curr <= 10000000000000000 && curr > max_start) {
                max_start = curr;
            }
        }
    } while(next_permutation(perm.begin(), perm.end()));
    assert(max_start == 6531031914842725);
    return 0;
}
