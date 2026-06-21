#include "geometry.h"

double Point::d(const Point &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

double Triangle::area() const {
    double A = a.d(b);
    double B = b.d(c);
    double C = c.d(a);
    double s = (A + B + C) / 2;
    return sqrt(s * (s - A) * (s - B) * (s - C));
}

bool Triangle::strictly_contains(const Point &p) const {
    double A = area();
    double A1 = Triangle(a, b, p).area();
    double A2 = Triangle(b, c, p).area();
    double A3 = Triangle(c, a, p).area();
    return !equal(A1, 0.0f) && !equal(A2, 0.0f) && !equal(A3, 0.0f) && equal(A, A1 + A2 + A3);
}

bool equal(double a, double b) {
    return fabs(a - b) < 1e-5;
}
