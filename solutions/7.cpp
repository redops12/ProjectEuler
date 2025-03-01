#include "prime.h"
#include <iostream>
#include <cassert>

using namespace std;

int generate_prime(int idx) {
    PrimeIterator it = PrimeIterator();
    for (int i = 0; i < idx; i++) {
        ++it;
    }
    return *it;

}

int main (int argc, char *argv[]) {
    assert(generate_prime(1) == 2);

    return 0;
}
