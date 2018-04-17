//
// Created by liu on 17-12-30.
//

#ifndef CPPLIGHT_LINE_H
#define CPPLIGHT_LINE_H


#include "Point.h"

class Radial {
    public:
        Point point;
        Vector direction;

        Radial(const Point &point, const Vector &direction);

        Radial(const Point &point, double directionX, double directionY);

        virtual ~Radial();
};


#endif //CPPLIGHT_LINE_H
