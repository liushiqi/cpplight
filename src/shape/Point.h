//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_POINT_H
#define CPPLIGHT_POINT_H

#include <utility>
#include <set>
#include "Vector.h"

class Shape;

class Point {
    public:
        double x, y;

        Point(double x, double y);

        Point(const Vector &vector);

        Point(const Point &another);

        ~Point();

        void setPosition(double x, double y);

        Point operator+(const Vector &vector) const;

        Point &operator+=(const Vector &vector);

        Point operator-(const Vector &vector) const;

        Point &operator-=(const Vector &vector);

        Point operator/(double proportion) const;
        
        Point &operator/=(double proportion);
        
        Point operator/(const Vector &proportion) const;
        
        Point &operator/=(const Vector &proportion);

        Vector operator-(const Point &point) const;
};


class IntersectPoint : virtual public Point {
    public:
        double distance;
        double emissive;

        IntersectPoint(double x, double y, double distance, double emissive);

        IntersectPoint(const Vector &vector, double distance, double emissive);

        IntersectPoint(const IntersectPoint &point);

        bool operator<(const IntersectPoint &point) const;
};

#endif //CPPLIGHT_POINT_H
