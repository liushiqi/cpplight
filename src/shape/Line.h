//
// Created by liu on 17-12-30.
//

#ifndef CPPLIGHT_LINE_H
#define CPPLIGHT_LINE_H


#include "Point.h"

class Line {
    public:
        Point point;
        Vector direction;

        Line(const Point &point, const Vector &direction);

        Line(const Point &point, double directionX, double directionY);

        virtual ~Line();
};


#endif //CPPLIGHT_LINE_H
