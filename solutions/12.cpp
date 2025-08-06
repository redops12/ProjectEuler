#include <iostream>

using namespace std;

int main() {
    int current = 1;
    int triangle = 1;
    int max_divisors = 0;
    while (true) {
        int divisors = 0;
        for (int i = 1; i < triangle; i++) {
            if (i * i > triangle) break;
            divisors += 2 * (triangle % i == 0);
        }
        if (divisors > 500) {
            cout << triangle << endl;
            break;
        }
        if (divisors > max_divisors) {
            cout << divisors << " " << triangle << endl;
        }
        current++;
        triangle += current;
    }
}
