#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    vector<int> bitmask1(4, 0);
    bitmask1.resize(10, 1);
    unsigned int count = 0;
    do {
        set<unsigned int> die1;
        for (size_t i = 0; i < bitmask1.size(); i++) {
            if (bitmask1[i]) {
                die1.insert(i);
                if (i == 6) die1.insert(9);
                if (i == 9) die1.insert(6);
            }
        }
        vector<int> bitmask2(4, 0);
        bitmask2.resize(10, 1);
        do {
            set<unsigned int> die2;
            for (size_t i = 0; i < bitmask2.size(); i++) {
                if (bitmask2[i]) {
                    die2.insert(i);
                    if (i == 6) die2.insert(9);
                    if (i == 9) die2.insert(6);
                }
            }
            if (
                    ((die1.contains(0) && die2.contains(1)) || (die2.contains(0) && die1.contains(1))) &&
                    ((die1.contains(0) && die2.contains(4)) || (die2.contains(0) && die1.contains(4))) &&
                    ((die1.contains(0) && die2.contains(9)) || (die2.contains(0) && die1.contains(9))) &&
                    ((die1.contains(1) && die2.contains(6)) || (die2.contains(1) && die1.contains(6))) &&
                    ((die1.contains(2) && die2.contains(5)) || (die2.contains(2) && die1.contains(5))) &&
                    ((die1.contains(3) && die2.contains(6)) || (die2.contains(3) && die1.contains(6))) &&
                    ((die1.contains(4) && die2.contains(9)) || (die2.contains(4) && die1.contains(9))) &&
                    ((die1.contains(6) && die2.contains(4)) || (die2.contains(6) && die1.contains(4))) &&
                    ((die1.contains(8) && die2.contains(1)) || (die2.contains(8) && die1.contains(1)))
               ) {
                count++;
            }
        } while(next_permutation(bitmask2.begin(), bitmask2.end()));
    } while(next_permutation(bitmask1.begin(), bitmask1.end()));
    cout << count / 2 << endl;

    return 0;
}
