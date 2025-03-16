#include <iostream>
#include <cassert>
#include <cstdint>
#include <set>

using namespace std;

int main (int argc, char *argv[]) {
    uint64_t t_idx = 285;
    uint64_t p_idx = 165;
    uint64_t h_idx = 143;
    while (true) {
        t_idx++;
        uint64_t t_num = t_idx * (t_idx + 1) / 2;
        uint64_t p_num = p_idx * (3 * p_idx - 1) / 2;
        uint64_t h_num = h_idx * (2 * h_idx - 1);
        if (t_num == p_num && t_num == h_num) {
            cout << t_num << endl;
            break;
        }
        if (p_num < t_num) p_idx++;
        if (h_num < t_num) h_idx++;
    }
    return 0;
}
