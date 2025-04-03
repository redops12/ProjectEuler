#include <iostream>
#include <cassert>
#include <array>
#include <cstdint>

using namespace std;

int main (int argc, char *argv[]) {
    array<uint64_t, 101> p = {};
    p[0] = 1;
    for (int i = 1; i < 101; i++) {
        int mult = 1;
        for (int k = 1; i - (k * ( 3 * k - 1) / 2) >= 0; k++) {
            if (i - (k * ( 3 * k - 1) / 2) >= 0) {
                p[i] += mult * p[i - (k * ( 3 * k - 1) / 2)];
            }
            if (i - (k * ( 3 * k + 1) / 2) >= 0) {
                p[i] += mult * p[i - (k * ( 3 * k + 1) / 2)];
            }
            mult *= -1;
        }
    }
    cout << p[100] - 1 << endl;

    return 0;
}
