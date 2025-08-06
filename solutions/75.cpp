#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {

    size_t N = 1500000;
    // for m and n odd and coprime m > n
    // L = k * (m^2 - n^2)/2 + k * mn + k * (m^2 + n^2)/2
    // L = k m(m + n)
    vector<unsigned int> counts(N,0);
    unsigned int count = 0;
    for (unsigned int m = 3; m * m < N; m += 2) {
        vector<unsigned int> coprimes = get_coprime(m);
        for(auto n : coprimes) {
            if (n % 2 == 0) continue;
            unsigned int mult = m * (m + n);
            for (size_t i = mult; i < counts.size(); i += mult){
                counts[i]++;
            }
        }
    }
    for(auto x : counts) {
        if (x == 1) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
