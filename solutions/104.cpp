#include "strint.h"
#include <iostream>

using namespace std;

int main() {
    unsigned int last_num1 = 1;
    unsigned int last_num2 = 1;
    uint64_t num1 = 1;
    uint64_t num2 = 1;
    int idx = 2;
    uint64_t all_digs = 123456789;
    unsigned int last_all_digs = 123456789;
    while (true) {
        unsigned int last_9 = last_num2 % 1000000000;
        if (is_perm(last_9, last_all_digs)) {
            unsigned int log = log_10(num2);
            uint64_t first_9 = num2;
            while (log > 8) {
                first_9 /= 10;
                log--;
            }
            if (is_perm(first_9, all_digs)) {
                assert(idx == 329468);
                return 0;
            }
        }
        uint64_t temp = num1 + num2;
        num1 = num2;
        num2 = temp;
        unsigned int log = log_10(num2);
        // only track the top 50 digits
        while (log > 15) {
            num2 /= 10;
            num1 /= 10;
            log--;
        }
        unsigned int temp2 = last_num1 + last_num2;
        last_num1 = last_num2 % 1000000000;
        last_num2 = temp2 % 1000000000;
        idx++;
    }
}
