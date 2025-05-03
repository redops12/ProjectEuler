#include "prime.h"
#include <map>
#include <vector>
#include <iostream>
#include <cstdint>
#include <cassert>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    // Sum x Number of coins
    vector<vector<uint64_t>> number_of_ways(1, vector<uint64_t>(1, 1));
    size_t max_i = 0;
    size_t max_j = 0;
    while (number_of_ways[max_i][max_j] <= 5000) {
        max_j += 1;
        number_of_ways[0].push_back(0);
        PrimeIterator pit;
        for (size_t i = 1; i <= max_i; i++, ++pit) {
            number_of_ways[i].push_back(number_of_ways[i-1][max_j]);
            if (max_j >= *pit) number_of_ways[i][max_j] += number_of_ways[i][max_j - *pit];
        }
        if (*pit <= max_j) {
            max_i += 1;
            number_of_ways.push_back(vector<uint64_t>(max_j + 1, 0));
            for (size_t j = 0; j <= max_j; j++) {
                number_of_ways[max_i][j] += number_of_ways[max_i-1][j];
                if (j >= *pit) number_of_ways[max_i][j] += number_of_ways[max_i][j - *pit];
            }
        }
    }
    assert(max_j == 71);
    return 0;
}
