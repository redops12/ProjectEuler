#include "strint.h"
#include "prime.h"
#include <iostream>
#include <cassert>
#include <deque>

using namespace std;

int main() {
    deque<int> num = {9,8,7,6,5,4,3,2,1};
    do {
        do {
            if (is_prime(concat(num.begin(), num.end()))) {
                cout << concat(num.begin(), num.end()) << endl;
                return 0;
            }
        } while (prev_permutation(num.begin(), num.end()));
        num.pop_front();
    } while (!num.empty());
    return 0;
}
