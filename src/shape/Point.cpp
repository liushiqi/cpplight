//
// Created by liu on 17-12-22.
//

#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point &another) = default;

Point::Point(const Vector &vector) : Point(vector.x, vector.y) {}

Point::~Point() = default;

void Point::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector Point::operator-(const Point &point) const {
    return Vector(x - point.x, y - point.y);
}
