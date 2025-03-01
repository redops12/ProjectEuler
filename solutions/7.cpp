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
    assert(generate_prime(0) == 2);
    assert(generate_prime(1) == 3);
    assert(generate_prime(2) == 5);
    assert(generate_prime(3) == 7);
    int prime = generate_prime(10000);
    cout << prime << endl;
    assert(prime == 104743);

    return 0;
}
