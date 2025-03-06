#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> single_digit_nums = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};
vector<string> teens = {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};
vector<string> tens = {
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};

void print_char(int i) {
        int mod_100 = i % 100;
        if (i == 1000) {
            cout << "onethousand";
            return;
        }
        if (i >= 100) {
            cout << single_digit_nums[i/100] << "hundred";
            if (i % 100 != 0) cout << "and";
        }

        if (mod_100 >= 20) cout << tens[mod_100/10];
        if (mod_100 < 10 || mod_100 >= 20) cout << single_digit_nums[mod_100 % 10];
        if (mod_100 >= 10 && mod_100 < 20) cout << teens[mod_100 % 10];

}

int main(int argc, char * argv[]) {
    for (int i = 0; i <= 1000; i++) {
        print_char(i);
    }
}
