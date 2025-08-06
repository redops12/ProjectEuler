#include "prime.h"
#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int main() {
    for (int i = 645; true; i++) {
        set<int> factors;
        bool answer = true;
        for (int j = i; j < i + 4; j++) {
            Factorized f(j);
            if (f.factors.size() != 4) {
                answer = false;
                break;
            }
        }
        if (answer) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
