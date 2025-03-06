#include <map>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    map<int, int> sums;
    for (int i = 1; i < 10000; i++) {
        int sum = 0;
        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        sums[i] = sum;
    }
    int grand_sum = 0;
    for (auto p : sums) {
        if (p.first == p.second) continue;
        if (sums[p.second] == p.first) grand_sum += p.first;
    }
    cout << grand_sum << endl;
    return 0;
}
