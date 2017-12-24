//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_VECTOR_H
#define CPPLIGHT_VECTOR_H

class Point;
class Vector {
    public:
        double x, y;

        Vector(double x, double y);

        Vector(const Point &point);

        Vector(const Vector &vector);


};

#endif //CPPLIGHT_VECTOR_H
