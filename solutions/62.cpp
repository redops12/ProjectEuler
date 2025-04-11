#include "strint.h"
#include <iostream>
#include <cassert>
#include <cstdint>
#include <map>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    // pair represents the first and the count
    map<uint64_t, pair<uint64_t,int>> cube_count;
    uint64_t max = 1000000000000000000;
    for (uint64_t i = 0; ; i++) {
        uint64_t cube = i * i * i;
        if (cube > max) {
            break;
        }
        vector<unsigned int> digs = get_digits(cube);
        sort(digs.begin(), digs.end(), greater<int>());
        uint64_t conc = concat(digs.begin(), digs.end());
        auto it = cube_count.find(conc);

        if (it == cube_count.end()) {
            cube_count[conc] = make_pair(cube, 1);
        } else {
            it->second.second++;
            if (it->second.second == 5) {
                max = base_10(cube);
            }
        }
    }

    uint64_t min_cube = UINT64_MAX;
    for (auto p : cube_count) {
        if (p.second.second >= 5) {
            min_cube = min(min_cube, p.second.first);
        }
    }
    assert(min_cube == 127035954683);

    return 0;
}
