#include "strint.h"
#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

int main (int argc, char *argv[]) {
    static const int MAX_BOUND = 1000000;
    static const array<int,10> factorial = {1,1,2,6,24,120,720,5040,40320,362880};
    unordered_map<int, int> cycles;
    cycles[1] = 1;
    cycles[2] = 1;
    cycles[145] = 1;
    cycles[40585] = 1;
    cycles[169] = 3;
    cycles[363601] = 3;
    cycles[1454] = 3;
    cycles[871] = 2;
    cycles[45361] = 2;
    cycles[872] = 2;
    cycles[45362] = 2;
    int count = 0;
    vector<int> tests;
    tests.reserve(60);
    for (size_t i = 1; i < MAX_BOUND; i++) {
        tests.push_back(i);

        while (cycles[tests.back()] == 0) {
            DigIterator dit(tests.back());
            int new_test = 0;
            for (;dit != dit.end(); ++dit) {
                new_test += factorial[*dit];
            }
            tests.push_back(new_test);
        }
        int last_cycle_len = cycles[tests.back()];
        while (tests.size() != 1) {
            tests.pop_back();
            last_cycle_len++;
            cycles[tests.back()] = last_cycle_len;
        }
        tests.pop_back();
        if (last_cycle_len == 60) {
            count++;
        }
    }
    assert(count == 402);

    return 0;
}
