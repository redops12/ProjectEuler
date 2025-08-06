#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

int main() {
    ostringstream ss;
    for (size_t i = 0; i < 200000; i++) {
        ss << i;
    }
    string s = ss.str();
    int num = 1;
    for (size_t i = 1; i <= 1000000; i *= 10) {
        num *= s[i] - '0';
    }
    cout << num;
    return 0;
}
