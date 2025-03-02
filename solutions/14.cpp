#include <map>
#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

map<uint64_t, int> known_lengths;

uint64_t chain_length(uint64_t x) {
    if (x == 1 || x == 0) return 1;
    if (x < 0) abort();
    auto lookup = known_lengths.find(x);
    if (lookup != known_lengths.end()) {
        return lookup->second;
    } else {
        uint64_t new_length = chain_length((x % 2) ? 3 * x + 1 : x / 2) + 1;
        known_lengths[x] = new_length;
        return new_length;
    }
}

int main(int argc, char * argv[]) {
    uint64_t max_num = 0;
    for (uint64_t i = 0; i < 1000000; i++) {
        int rc = chain_length(i);
        if (max_num < rc) {
            max_num = rc;
            cout << i << " " << rc << endl;
        }
    }
    cout << max_num << endl;
}


