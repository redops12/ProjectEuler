#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <cstdint>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    string expr = "*123456789=";
    set<int> seen;
    do {
        if (expr[0] == '*' || expr[0] == '=' || expr.back() == '*' || expr.back() == '=') continue;
        bool bad_string = false;
        for (int i = 0; i < expr.length() - 1; i++) {
            if (expr[i] == '*') {
                if (expr[i+1] == '=') {
                    bad_string = true;
                }
                break;
            }
            if (expr[i] == '=') {
                bad_string = true;
                break;
            }
        }
        if (bad_string) continue;
        stringstream ss(expr);
        char black_hole;
        int multiplicand, multiplier, product;
        ss >> multiplicand >> black_hole >> multiplier >> black_hole >> product;
        if (multiplicand * multiplier == product) {
            seen.insert(product);
        }
    } while (next_permutation(expr.begin(), expr.end()));
    uint64_t sum = 0;
    for (int x : seen) {
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
