#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    enum ops {
        MULT = 0,
        DIV = 1,
        ADD = 2,
        SUB = 3,
    };

    using BinaryOp = function<Frac<int>(Frac<int>, Frac<int>)>;
    vector<BinaryOp> ops = {
        [](Frac<int> a, Frac<int> b) {return a * b;},
        [](Frac<int> a, Frac<int> b) {return b == 0 ? 0 : a / b;},
        [](Frac<int> a, Frac<int> b) {return a + b;},
        [](Frac<int> a, Frac<int> b) {return a - b;},
    };

    vector<bool> bitmask(6, false);
    bitmask.resize(10, true);
    unsigned int max_val = 0;
    vector<unsigned int> max_digs;
    do {
        vector<unsigned int> digs;
        for (size_t i = 0; i < bitmask.size(); i++) {
            if (bitmask[i]) {
                digs.push_back(i);
            }
        }

        set<Frac<int>> seen;
        do {
            for (unsigned int i = 0; i <= 0x3f; i++) {
                BinaryOp op1 = ops[ i & 0x3];
                BinaryOp op2 = ops[(i & 0xc) >> 2];
                BinaryOp op3 = ops[(i & 0x30) >> 4];
                seen.insert(op3(op2(op1(digs[0], digs[1]),digs[2]),digs[3]));
                seen.insert(op2(op1(digs[0], digs[1]),op3(digs[2],digs[3])));
                seen.insert(op3(op1(digs[0], op2(digs[1],digs[2])),digs[3]));
                seen.insert(op1(digs[0], op3(op2(digs[1],digs[2]),digs[3])));
                seen.insert(op1(digs[0], op2(digs[1],op3(digs[2],digs[3]))));
            }
        } while (next_permutation(digs.begin(), digs.end()));
        unsigned int i;
        for (i = 1; seen.contains(i); i++) {}
        if (i > max_val) {
            max_val = i;
            max_digs = digs;
        }
    } while(next_permutation(bitmask.begin(), bitmask.end()));
    assert(max_digs[0] == 1 && max_digs[1] == 2 && max_digs[2] == 5 && max_digs[3] == 8);

    return 0;
}
