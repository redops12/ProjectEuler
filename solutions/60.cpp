#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cassert>
#include "prime.h"
#include "strint.h"
#include "functions.h"

using namespace std;

int main (int argc, char *argv[]) {
    map<int, vector<int>> nonsense;
    for (PrimeIterator it1; *it1 < 10000; ++it1) {
        for (PrimeIterator it2 = it1 + 1; *it2 < 10000; ++it2) {
            if (is_prime(concat(*it1, *it2)) && is_prime(concat(*it2, *it1))) {
                nonsense[*it1].push_back(*it2);
            }
        }
    }
    vector<vector<int>> quints;
    for (auto k : nonsense) {
        int n1 = k.first;
        for (auto n2 : k.second) {
            vector<int> out2(k.second.size());
            auto it = set_intersection(
                    k.second.begin(), k.second.end(),
                    nonsense[n2].begin(), nonsense[n2].end(),
                    out2.begin()
                    );
            out2.resize(it - out2.begin());
            for (auto n3 : out2) {
                vector<int> out3(out2.size());
                it = set_intersection(
                        out2.begin(), out2.end(),
                        nonsense[n3].begin(), nonsense[n3].end(),
                        out3.begin()
                        );
                out3.resize(it - out3.begin());
                for (auto n4 : out3) {
                    vector<int> out4(out3.size());
                    it = set_intersection(
                            out3.begin(), out3.end(),
                            nonsense[n4].begin(), nonsense[n4].end(),
                            out4.begin()
                            );
                    out4.resize(it - out4.begin());
                    if (!out4.empty()) {
                        for (auto n5 : out4) {
                            quints.push_back({n1, n2, n3, n4, n5});
                        }
                    }
                }
            }
        }
    }
    /* cout << "quints" << endl; */
    int max_sum = 0;
    for (auto q : quints) {
        /* for (int term : q) { */
        /*     cout << term << " "; */
        /* } */
        /* cout << endl; */
        max_sum = max(max_sum, accumulate(q.begin(), q.end(), 0));
    }
    /* cout << max_sum << endl; */
    assert(26033 == max_sum);

    return 0;
}
