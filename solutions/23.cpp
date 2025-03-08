#include <set>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
    set<int> abundant_nums;
    for (int i = 0; i <= 28123; i++) {
        int divisor_sum = 0;
        for (int divisor = 1; divisor <= i / 2; divisor++) {
            if (i % divisor == 0) {
                divisor_sum += divisor;
            }
        }
        if (divisor_sum > i) {
            abundant_nums.insert(i);
        }
    }

    int sum_of_nums = 0;
    for (int i = 0; i <= 28123; i++) {
        bool sum_of_abundant = false;
        for (int j : abundant_nums) {
            if (abundant_nums.find(i - j) != abundant_nums.end()) {
                sum_of_abundant = true;
                break;
            }
        }
        if (!sum_of_abundant) {
            sum_of_nums += i;
        }
    }
    cout << sum_of_nums << endl;
}
