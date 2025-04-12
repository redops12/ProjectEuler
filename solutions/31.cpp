#include <map>
#include <vector>
#include <iostream>
#include <cstdint>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    // Sum x Number of coins
    vector<unsigned int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<vector<uint64_t>> number_of_ways(coins.size() + 1, vector<uint64_t>(201, 0));
    number_of_ways[0][0] = 1;
    for (size_t i = 1; i <= coins.size(); i++) {
        for (size_t j = 0; j <= 200; j++) {
            number_of_ways[i][j] += number_of_ways[i - 1][j];
            if (j >= coins[i-1]) {
                number_of_ways[i][j] += number_of_ways[i][j - coins[i - 1]];
            }
        }
    }
    cout << number_of_ways[coins.size()][200] << endl;
    return 0;
}
