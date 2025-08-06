#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int max_solutions = 0;
    size_t max_p = 0;
    for (size_t p = 0; p < 1000; p++) {
        int num_solutions = 0;
        for (size_t a = 1; a < p/3; a++) {
            for (size_t b = a; b < (2 * p) / 3 + 1; b++) {
                if (a + b > p) continue;
                size_t c = p - a - b;
                if (c > a + b) continue;
                if (c * c == a * a + b * b) num_solutions++;
            }
        }
        if (p == 120) assert(num_solutions == 3);
        if (max_solutions < num_solutions) {
            max_solutions = num_solutions;
            max_p = p;
        }
    }
    assert(max_p == 840);
    return 0;
}
