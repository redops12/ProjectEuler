#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>
#include "macros.h"

using namespace std;

void gen_seq(map<int,vector<pair<int, int>>> &genned_map, int (*generator)(int), int idx) {
    for (int i = 1; ; i++) {
        int ret = generator(i);
        if (ret >= 10000) {
            break;
        } else if (generator(i) >= 1000) {
            genned_map[ret / 100].push_back(make_pair(idx, ret));
        }
    }
}

class Path {
    public:
    set<int> used;
    vector<int> path;
    Path(vector<int> path, set<int> used): path(path), used(used) {}
};

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    // % 100 -> list[seq_idx, number]
    map<int,vector<pair<int, int>>> genned_map;
    // putting oct up front to cut down on recursions faster
    gen_seq(genned_map, [](int n) {return n * (n + 1) / 2;},        0);
    gen_seq(genned_map, [](int n) {return n * n;},                  1);
    gen_seq(genned_map, [](int n) {return n * (3 * n - 1) / 2;},    2);
    gen_seq(genned_map, [](int n) {return n * (2 * n - 1);},        3);
    gen_seq(genned_map, [](int n) {return n * (5 * n - 3) / 2;},    4);

    vector<Path> stack;
    for (int n = 0; n < 1000; n++) {
        int oct = n * (3 * n - 2);

        if (oct < 1000) {
            continue;
        } else if (oct >= 10000) {
            break;
        }

        Path p({oct},{});
        stack.push_back(p);
    }

    while (!stack.empty()) {
        Path current = stack.back();
        stack.pop_back();
        int next = current.path.back() % 100;
        auto steps = genned_map.find(next);
        if (steps == genned_map.end()) {
            continue;
        }
        for (auto p : steps->second) {
            if (current.used.find(p.first) != current.used.end()) {
                continue;
            }
            Path next = current;
            next.used.insert(p.first);
            next.path.push_back(p.second);
            if (next.path.size() == 6) {
                if (next.path[0] / 100 == p.second % 100) {
                    int sum = 0;
                    for (auto x : next.path) {
                        sum += x;
                    }
                    cout << sum << endl;
                    return 0;
                } else {
                    continue;
                }
            }
            stack.push_back(next);
        }
    }

    return 0;
}
