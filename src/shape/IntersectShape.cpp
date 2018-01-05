//
// Created by liu on 17-12-24.
//

#include "IntersectShape.h"

IntersectShape::IntersectShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

IntersectShape::~IntersectShape() {
    delete shape1;
    delete shape2;
}

std::pair<double, double> IntersectShape::distance(const Point &point) const {
    auto distance1 = shape1->distance(point), distance2 = shape2->distance(point);
    auto distance = distance1.first < distance2.first ? distance1: distance2;
    distance.first = distance1.first > distance2.first ? distance1.first : distance2.first;
    return distance;
}

std::vector<Point> IntersectShape::intersect(const Line &line) {
    // TODO
    return std::vector<Point>();
}
