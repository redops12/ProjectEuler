#include "prime.h"
#include "number_theory.h"
#include <iostream>
#include <cassert>
#include <set>
#include <map>

using namespace std;

inline uint64_t t(uint64_t n) {
    return 2 * n * n - 1;
}

struct cmp {
    bool operator()(unsigned int i, const std::pair<unsigned int, unsigned int>& p) const
    {
        return i < p.first;
    }

    bool operator()(const std::pair<unsigned int, unsigned int>& p, unsigned int i) const
    {
        return p.first < i;
    }
};

// https://math.stackexchange.com/questions/403519/primality-of-the-numbers-in-the-form-of-2n2-1
int main() {

    static const unsigned int MAX = 10000;
    map<unsigned int, unsigned int> seen;
    for (PrimeIterator pit(1.1 * MAX); *pit < 1.1 * MAX; ++pit) {
        if (!(*pit % 8 == 1 || *pit % 8 == 7))
            continue;
        unsigned int inv_2 = (*pit + 1) / 2;
        unsigned int b = 0;
        for (unsigned int i = 0; i < *pit; i++) {
            if (i * i % *pit == inv_2) {
                b = i;
                break;
            }
        }
        cout << *pit << " " << min(b, static_cast<unsigned int>(*pit - b)) << " " << max(b, static_cast<unsigned int>(*pit - b)) << endl;
        for (size_t i = *pit; i <= 1.1 * MAX; i += *pit) {
            if (i + b <= MAX)
                seen[i + b]++;
            if (i - b <= MAX)
                seen[i - b]++;
        }
    }

    // MAX - sum 2 * MAX/p for p = 1,7 mod 8
    cout << MAX - 1 - seen.size() << endl;

    return 0;
}
