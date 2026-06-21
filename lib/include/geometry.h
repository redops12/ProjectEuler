#include <vector>
#include <cmath>

class Point {
public:
    Point(int x, int y): x(x), y(y) {}
    int x;
    int y;
    double d(const Point &other) const;
};

class Triangle {
public:
    Triangle(Point a, Point b, Point c): a(a), b(b), c(c) {}
    Point a, b, c;

    double area() const;
    bool strictly_contains(const Point &p) const;
};

bool equal(double a, double b);
