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

IntersectPoint::IntersectPoint(double x, double y, double distance, double emissive) : Point(x, y), distance(distance),
                                                                                       emissive(emissive) {}

IntersectPoint::IntersectPoint(const Vector &vector, double distance, double emissive) : Point(vector),
                                                                                         distance(distance),
                                                                                         emissive(emissive) {}

IntersectPoint::IntersectPoint(const IntersectPoint &point) = default;

bool IntersectPoint::operator<(const IntersectPoint &point) const {
    return distance < point.distance;
}
