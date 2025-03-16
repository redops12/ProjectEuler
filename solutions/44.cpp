#include <iostream>
#include <cassert>
#include <cstdint>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    set<uint64_t> pengtagonal_nums = {1};
    int stopping_point = 2500;
    for (size_t n = 2; n < stopping_point; n++) {
        uint64_t next = *pengtagonal_nums.rbegin() + 3 * n - 2;
        pengtagonal_nums.insert(next);
    }

    uint64_t minimal_distance = UINT64_MAX;
    for(auto it = pengtagonal_nums.begin(); it != pengtagonal_nums.end(); ++it) {
        auto it2 = it;
        ++it2;
        for(; it2 != pengtagonal_nums.end(); ++it2) {
            if (pengtagonal_nums.find(*it2 - *it) != pengtagonal_nums.end() && pengtagonal_nums.find(*it2 + *it) != pengtagonal_nums.end()) {
                minimal_distance = min(*it2 - *it, minimal_distance);
            }
        }
    }
    cout << minimal_distance << endl;

    return 0;
}
