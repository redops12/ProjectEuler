#include "prime.h"
#include <iostream>
#include <cassert>
#include <map>

using namespace std;

int main (int argc, char *argv[]) {
    return 0;
    map<int,int> total_factors;
    // this solution is too slow need a new one
    for (int i = 1; i < 10000000; i++) {
        Factorized f(i);
        for (auto p : f.factors) {
            total_factors[p.first] += p.second;
        }
    }
    cout << "done" << endl;

    return 0;
}
