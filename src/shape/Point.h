//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_POINT_H
#define CPPLIGHT_POINT_H

#include <utility>
#include <set>
#include "Vector.h"

class Shape;

struct Compare {
    bool operator()(const std::pair<Point, double> &points1,
                    const std::pair<Point, double> &points2);
};

class Point {
    public:
        double x, y;

        Point(double x, double y);

        Point(const Vector &vector);

        Point(const Point &another);

        ~Point();

        void setPosition(double x, double y);

        Vector operator-(const Point &point) const;
};

#endif //CPPLIGHT_POINT_H
