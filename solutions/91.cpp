#include <iostream>
#include <cassert>
#include <eigen3/Eigen/Dense>
#include "macros.h"

using namespace std;
using namespace Eigen;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    int triangles = 0;
    int N = 50 + 1;
    for (size_t x1 = 0; x1 < N; x1++) {
        for (size_t y1 = 0; y1 < N; y1++) {
            for (size_t x2 = 0; x2 < N; x2++) {
                for (size_t y2 = 0; y2 < N; y2++) {
                    // first exclude any for which (x1, y1) has a lower slope than (x2, y2)
                    // y1/x2 <= y2/x2 -> x2 * y1 <= x1 * y2
                    if ((x2 * y1 <= x1 * y2) || (x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) {
                        continue;
                    }

                    Vector2i v1(x1,y1);
                    Vector2i v2(x2,y2);
                    if (v1.dot(v2) == 0 || v1.dot(v2 - v1) == 0 || v2.dot(v2 - v1) == 0) {
                        triangles++;
                    }
                }
            }
        }
    }
    cout << triangles << endl;


    return 0;
}
