//
// Created by liu on 17-12-24.
//

#include "SubtractShape.h"

SubtractShape::SubtractShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

SubtractShape::~SubtractShape() {
    delete shape1;
    delete shape2;
}

std::pair<double, double> SubtractShape::distance(const Point &point) const {
    auto distance1 = shape1->distance(point), distance2 = shape2->distance(point);
    auto distance = distance1;
    distance.first = distance1.first > -distance2.first ? distance1.first : -distance2.first;
    return distance;
}

std::vector<Point> SubtractShape::intersect(const Line &line) {
    // TODO
    return std::vector<Point>();
}
