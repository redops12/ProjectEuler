#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "roman_numeral.h"

using namespace std;

class NumeralMap {
    public:
    static const unordered_map<char, unsigned int> dig_to_val;
    static const vector<pair<unsigned int, string>> val_to_dig;
};

const unordered_map<char, unsigned int> NumeralMap::dig_to_val = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

const vector<pair<unsigned int, string>> NumeralMap::val_to_dig = {
    {1000,  "M"},
    {900,   "CM"},
    {500,   "D"},
    {400,   "CD"},
    {100,   "C"},
    {90,    "XC"},
    {50,    "L"},
    {40,    "XL"},
    {10,    "X"},
    {9,     "IX"},
    {5,     "V"},
    {4,     "IV"},
    {1,     "I"},
};

unsigned int to_number(const string& s) {
    unsigned int total = 0;
    unsigned int prev = 0;
    for (char c : s) {
        unsigned int curr = 0;
        try {
            curr = NumeralMap::dig_to_val.at(c);
        } catch (const out_of_range &e) {
            break;
        }

        if (prev < curr) {
            total += curr - prev - prev;
        } else {
            total += curr;
        }
        prev = curr;
    }
    return total;
}

string to_numeral(unsigned int num) {
    string ret;
    for (auto p : NumeralMap::val_to_dig) {
        while (num != 0 && p.first <= num) {
            ret.append(p.second);
            num -= p.first;
        }
    }
    return ret;
}
