#include "number_theory.h"
#include "prime.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char * argv[]) {
    int count = 0;;
    for (int i = 1; i < 10000; i++) {
        if (fast_is_square(i)) continue;
        ContinuedFrac cf(i);
        if (cf.repeated.size() % 2 == 1) {
            count++;
        }
    }
    cout << count << endl;
}
