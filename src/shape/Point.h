//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_POINT_H
#define CPPLIGHT_POINT_H

#include "Vector.h"

class Point {
    public:
        double x, y;

        Point(double x, double y);

        Point(const Vector &vector);

        Point(const Point &another);

        ~Point();

        void setPosition(double x, double y);
};

#endif //CPPLIGHT_POINT_H
