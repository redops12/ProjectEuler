#include "strint.h"
#include "prime.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    /* vector<int> digs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; */
    vector<int> digs = {1,4,0,6,3,5,7,2,8,9};
    uint64_t sum = 0;
    do {
        bool include = true;
        PrimeIterator pit;
        for (int i = 1; i < digs.size() - 2; i++) {
            uint64_t num = concat(digs.begin() + i, digs.begin() + i + 3);
            if (num % *pit != 0) {
                include = false;
                break;
            }
            ++pit;
        }
        if (include) {
            sum += concat(digs.begin(), digs.end());
        }
    } while (next_permutation(digs.begin(), digs.end()));
    cout << sum << endl;
    return 0;
}
