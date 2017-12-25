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

        double operator*(const Vector &vector) const;

        Vector operator+(const Vector &vector) const;

        Vector &operator+=(const Vector &vector);

        Vector operator-(const Vector &vector) const;

        Vector &operator-=(const Vector &vector);

        double length() const;
};

#endif //CPPLIGHT_VECTOR_H
