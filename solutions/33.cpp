#include "number_theory.h"
#include <iostream>
#include <string>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    Frac<int> product(1,1);
    // check for numbers ij/ki
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                int num = i * 10 + j;
                int denom = k * 10 + i;
                if (num >= denom) continue;
                Frac<int> start(num, denom);
                Frac<int> reduced(j, k);
                if (start == reduced) {
                    cout << static_cast<string>(start) << endl;
                    product = product * start;
                }
            }
        }
    }
    // check for numbers ji/ki
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                int num = j * 10 + i;
                int denom = k * 10 + i;
                if (num >= denom) continue;
                Frac<int> start(num, denom);
                Frac<int> reduced(j, k);
                if (start == reduced) {
                    cout << static_cast<string>(start) << endl;
                    product = product * start;
                }
            }
        }
    }
    // check for numbers ij/ik
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j == 0 && k == 0) continue;
                int num = i * 10 + j;
                int denom = i * 10 + k;
                if (num >= denom) continue;
                Frac<int> start(num, denom);
                Frac<int> reduced(j, k);
                if (start == reduced) {
                    cout << static_cast<string>(start) << endl;
                    product = product * start;
                }
            }
        }
    }
    // check for numbers ji/ik
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                int num = j * 10 + i;
                int denom = i * 10 + k;
                if (num >= denom) continue;
                Frac<int> start(num, denom);
                Frac<int> reduced(j, k);
                if (start == reduced) {
                    cout << static_cast<string>(start) << endl;
                    product = product * start;
                }
            }
        }
    }
    cout << static_cast<string>(product) << endl;
    assert(product == Frac(1,100));
    return 0;
}
