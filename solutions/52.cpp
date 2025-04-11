#include "strint.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    for (int i = 1; ;i++) {
        vector<unsigned int> digs = get_digits(i);
        sort(digs.begin(), digs.end());
        bool good = true;
        for (int mult = 2; mult <= 6; mult++) {
            vector<unsigned int> digs_mult = get_digits(i * mult);
            sort(digs_mult.begin(), digs_mult.end());
            if (digs != digs_mult) {
                good = false;
                break;
            }
        }
        if (good) {
            assert(i == 142857);
            break;
        }
    }

    return 0;
}
