//
// Created by liu on 17-12-24.
//

#include "Vector.h"
#include "Point.h"

Vector::Vector(double x, double y) : x(x), y(y) {}

Vector::Vector(const Point &point) : Vector(point.x, point.y) {}

Vector::Vector(const Vector &vector) : Vector(vector.x, vector.y) {}
