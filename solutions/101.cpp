#include <eigen3/Eigen/Dense>
#include <iostream>
#include <cassert>
#include "number_theory.h"

using namespace std;
using namespace Eigen;

int main () {
    // initialize x^3
    Polynomial<int64_t> p({1,-1,1,-1,1,-1,1,-1,1,-1,1});

    // seq
    vector<int64_t> out;
    for (unsigned int n = 1; n <= p.degree(); n++) {
        out.push_back(p(n));
    }

    int64_t bops = 0;
    for (size_t i = 0; i < out.size(); i++) {
        MatrixXd A(i + 1, i + 1);
        for (long j = 0; j < A.rows(); j++) {
            for (long k = 0; k < A.cols(); k++) {
                A(j, k) = pow(j + 1, k);
            }
        }
        VectorXd b(i + 1);
        for (long j = 0; j < b.size(); j++) {
            b(j) = out[j];
        }
        cout << A << endl;
        // TODO: These values are rounded which is killing the solution
        VectorXd new_coefs = A.inverse() * b;
        cout << new_coefs.transpose() << endl;
        Polynomial<int64_t> op(vector<int64_t>(new_coefs.data(), new_coefs.data() + new_coefs.size()));
        cout << op << endl;
        int64_t test_num = 1;
        while (op(test_num) == p(test_num)) {
            test_num++;
        }
        bops += op(test_num);
        cout << op(test_num) << endl;
    }
    cout << bops << endl;

    return 0;
}


