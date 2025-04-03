#include <iostream>
#include <cassert>

using namespace std;

int main (int argc, char *argv[]) {
    pair<int,int> max_frac = make_pair(2,5);
    int n = 2;
    int d = 5;
    while (d <= 1000000) {
        // n/d < 3/7
        if (n * 7 < d * 3) {
            // n/d > max_frac
            if (n * max_frac.second > d * max_frac.first) {
                max_frac.first = n;
                max_frac.second = d;
            }
            n++;
        } else { // n/d >= 3/7
            d++;
        }
    }
    cout << max_frac.first << endl;

    return 0;
}
