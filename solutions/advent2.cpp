#include "strint.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;
vector<pair<uint64_t, uint64_t>> num_ranges = {
    make_pair(12077, 25471),
    make_pair(4343258, 4520548),
    make_pair(53, 81),
    make_pair(43661, 93348),
    make_pair(6077, 11830),
    make_pair(2121124544, 2121279534),
    make_pair(631383, 666113),
    make_pair(5204516, 5270916),
    make_pair(411268, 591930),
    make_pair(783, 1147),
    make_pair(7575717634, 7575795422),
    make_pair(8613757494, 8613800013),
    make_pair(4, 19),
    make_pair(573518173, 573624458),
    make_pair(134794, 312366),
    make_pair(18345305, 18402485),
    make_pair(109442, 132958),
    make_pair(59361146, 59451093),
    make_pair(1171, 2793),
    make_pair(736409, 927243),
    make_pair(27424, 41933),
    make_pair(93, 216),
    make_pair(22119318, 22282041),
    make_pair(2854, 4778),
    make_pair(318142, 398442),
    make_pair(9477235089, 9477417488),
    make_pair(679497, 734823),
    make_pair(28, 49),
    make_pair(968753, 1053291),
    make_pair(267179606, 267355722),
    make_pair(326, 780),
    make_pair(1533294120, 1533349219)
    };

int main () {
    uint64_t total_nums = 0;
    set<uint64_t> found_nums;
    for (const auto &range : num_ranges) {
        for (uint64_t i = range.first; i <= range.second; i++) {
            vector<unsigned int> digits = get_digits(i);

            for (size_t num_repeats = 2; num_repeats <= digits.size(); num_repeats++) {
                if (digits.size() % num_repeats != 0) {
                    continue;
                }
                size_t num_repeated_digs = digits.size() / num_repeats;
                for (size_t j = 0; j < num_repeated_digs; j++) {
                    bool bad = false;
                    for (size_t m = 1; m < num_repeats; m++) {
                        if (digits[j + num_repeated_digs * m] != digits[j]) {
                            bad = true;
                            break;
                        }
                    }
                    if (bad) {
                        break;
                    }
                    if (j == num_repeated_digs - 1) {
                        if (found_nums.find(i) != found_nums.end()) {
                            break;
                        }
                        found_nums.insert(i);
                        cout << i << endl;
                        total_nums += i;
                    }
                }
            }
        }
    }
    cout << total_nums << endl;
    return 0;
}
