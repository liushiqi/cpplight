//
// Created by liu on 17-12-24.
//

#include <algorithm>
#include "Vector.h"
#include "Point.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(const Point &point) : Vector(point.x, point.y) {}

Vector::Vector(const Vector &vector) : Vector(vector.x, vector.y) {}

double Vector::operator*(const Vector &vector) const {
    return x * vector.x + y * vector.y;
}

Vector Vector::operator+(const Vector &vector) const {
    return Vector(x + vector.x, y + vector.y);
}

Vector &Vector::operator+=(const Vector &vector) {
    *this = *this + vector;
    return *this;
}

Vector Vector::operator-(const Vector &vector) const {
    return Vector(x - vector.x, y - vector.y);
}

Vector &Vector::operator-=(const Vector &vector) {
    *this = *this - vector;
    return *this;
}

double Vector::length() const {
    return std::sqrt(x * x + y * y);
}