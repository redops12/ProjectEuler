#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <set>
#include <optional>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    const unsigned int MAX = 1000000;
    DivisorSum lookup(MAX);
    vector<optional<unsigned int>> chain_length(MAX + 1, nullopt);
    unsigned int max_path = 0;
    unsigned int global_min = 0;
    for (unsigned int i = 1; i <= MAX; i++) {
        if (chain_length[i].has_value()) continue;
        unsigned int length = 0;
        set<unsigned int> seen = {i};
        chain_length[i] = 0;
        unsigned int curr = i;
        while (true) {
            length++;
            unsigned int new_val = lookup.at_proper(curr);
            if (seen.contains(new_val)) {
                if (max_path < length - chain_length[new_val].value()) {
                    max_path = length - chain_length[new_val].value();
                    unsigned int min_number = MAX + 1;
                    for (auto x : seen) {
                        if (chain_length[x].value() >= chain_length[new_val].value()) {
                            min_number = min(min_number, x);
                        }
                    }
                    global_min = min_number;
                }
                break;
            }
            if (new_val > MAX || chain_length[new_val].has_value()) {
                break;
            }
            seen.insert(new_val);
            chain_length[new_val] = length;
            curr = new_val;
        }
    }
    cout << max_path << " " << global_min << endl;

    return 0;
}
