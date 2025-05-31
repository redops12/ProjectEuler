#include <iostream>
#include <cassert>
#include <vector>
#include "macros.h"

using namespace std;

int main (int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    vector<bool> bitmask(4,true);
    bitmask.resize(10, false);
    vector<unsigned int> digs = {0,1,2,3,4,5,6,7,8,9};
    

    return 0;
}
