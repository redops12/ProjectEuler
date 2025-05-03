#include <iostream>
#include <cassert>
#include <array>
#include <random>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    static const unsigned int GO = 0;
    static const unsigned int JAIL = 10;

    vector<unsigned int> arr(40, 0);
    unsigned int pos = 0;
    unsigned int doubles = 0;
    for (size_t i = 0; i < 1000000; i++) {
        // TODO handle doubles
        unsigned int roll1 = rand() % 4;
        unsigned int roll2 = rand() % 4;
        if (roll1 == roll2) {
            doubles++;
            if (doubles == 3) {
                pos = JAIL;
                arr[JAIL]++;
                doubles = 0;
                continue;
            }
        } else {
            doubles = 0;
        }
        unsigned int roll = 2 + roll1 + roll2;
        pos = (pos + roll) % 40;
        switch (pos) {
            // G2J
            case 30:
                pos = JAIL;
                break;
            case 7:
            case 22:
            case 36:
                switch (rand() % 16) {
                    case 0:
                        // GO
                        pos = GO;
                        break;
                    case 1:
                        // JAIL
                        pos = JAIL;
                        break;
                    case 2:
                        // C1
                        pos = 11;
                        break;
                    case 3:
                        // E3
                        pos = 24;
                        break;
                    case 4:
                        // H2
                        pos = 39;
                        break;
                    case 5:
                        // R1
                        pos = 5;
                        break;
                    case 6:
                    case 7:
                        if (pos < 5 || pos > 35) {
                            pos = 5;
                        } else if (pos < 15) {
                            pos = 15;
                        } else if (pos < 25) {
                            pos = 25;
                        } else {
                            pos = 35;
                        }
                        break;
                    case 8:
                        if (pos < 12 || pos > 28) {
                            pos = 12;
                        } else {
                            pos = 28;
                        }
                        break;
                    case 9:
                        pos -= 3;
                        break;
                    default:
                        break;
                }
                break;
            case 2:
            case 17:
            case 33:
                switch (rand() % 16) {
                    case 0:
                        pos = GO;
                        break;
                    case 1:
                        pos = JAIL;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        arr[pos]++;
    }

    unsigned int max1 = 0, max2 = 0, max3 = 0;
    unsigned int pos_max1 = 0, pos_max2 = 0, pos_max3 = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > max1) {
            max3 = max2;
            pos_max3 = pos_max2;
            max2 = max1;
            pos_max2 = pos_max1;
            max1 = arr[i];
            pos_max1 = i;
        } else if (arr[i] > max2) {
            max3 = max2;
            pos_max3 = pos_max2;
            max2 = arr[i];
            pos_max2 = i;
        } else if (arr[i] > max3) {
            max3 = arr[i];
            pos_max3 = i;
        }
    }
    cout << pos_max1 << pos_max2 << pos_max3 << endl;

    return 0;
}
