#include <iostream>
#include <cassert>
#include <vector>
#include "macros.h"

using namespace std;

inline unsigned int tri(unsigned int n) {
    return n * (n + 1) / 2;
}

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    unsigned int max_n = 0;
    for (max_n = 1; tri(max_n) < 2000000; max_n++) {}

    size_t i = max_n, j = 1;
    size_t closest_value = tri(max_n) - 2000000;
    size_t closest_area = max_n;
    while (i >= j) {
        int dist = tri(i) * tri(j) - 2000000;
        if (static_cast<unsigned int>(abs(dist)) < closest_value) {
            closest_value = static_cast<unsigned int>(abs(dist));
            closest_area = i * j;
        }
        if (dist > 0) {
            i--;
        } else {
            j++;
        }
    }

    cout << closest_area << endl;

    return 0;
}
