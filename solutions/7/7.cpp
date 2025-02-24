#include "../../lib/prime.h"
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    PrimeIterator it = PrimeIterator();
    for (int i = 0; i < 10001; i++) {
        ++it;
    }
    cout << *it << endl;
    return 0;
}
