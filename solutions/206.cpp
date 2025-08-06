#include <cstdint>
#include <iostream>

using namespace std;

int main() {
    for (uint64_t x = 1010101010; ;x+=10) {
        uint64_t sq = x * x;
        if (
                sq % 10 == 0 &&
                (sq / 100) % 10 == 9 &&
                (sq / 10000) % 10 == 8 &&
                (sq / 1000000) % 10 == 7 &&
                (sq / 100000000) % 10 == 6 &&
                (sq / 10000000000) % 10 == 5 &&
                (sq / 1000000000000) % 10 == 4 &&
                (sq / 100000000000000) % 10 == 3 &&
                (sq / 10000000000000000) % 10 == 2 &&
                (sq / 1000000000000000000) % 10 == 1
           ) {
            cout << x << endl;
            break;
        }
    }
    return 0;
}
