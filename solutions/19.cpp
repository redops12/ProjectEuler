#include <vector>
#include <iostream>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int sundays = 0;
    // refers to jan 1 1900
    int day_count = 0;
    // skip 1900
    day_count += 365;
    vector<int> day_counts_non_leap = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> day_counts_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int year = 1901; year <= 2000; year++) {
        bool is_leap = (year % 4 == 0) && !(year % 100 == 0 && year % 400 != 0);
        for (int days : (is_leap) ? day_counts_leap : day_counts_non_leap) {
            if (day_count % 7 == 6) {
                sundays++;
            }
            day_count += days;
        }
    }
    cout << sundays << endl;

    return 0;
}
