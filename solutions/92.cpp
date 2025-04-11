#include "strint.h"
#include <iostream>
#include <cassert>
#include <array>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int count = 0;
    vector<uint8_t> arr(648, 0);
    arr[1] = 1;
    arr[89] = 89;
    for (int i = 1; i < 648; i++) {
        vector<int> stack = {i};
        while (arr[stack.back()] == 0) {
            DigIterator<int> dig(stack.back());
            stack.push_back(0);
            for (; dig != dig.end(); ++dig) {
                stack.back() += *dig * *dig;
            }
        }
        uint8_t res = arr[stack.back()];
        for(auto x : stack) {
            arr[x] = res;
        }
        if (res == 89) {
            count++;
        }
    }
    for (int i = 648; i < 10000000; i++) {
        int num = 0;
        for (DigIterator<int> dig(i); dig != dig.end(); ++dig) {
            num += *dig * *dig;
        }
        assert(num < 648);
        if (arr[num] == 89) {
            count++;
        }
    }
    assert(count == 8581146);

    return 0;
}
