//
// Created by liu on 17-12-24.
//

#include "UnionShape.h"

UnionShape::UnionShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

UnionShape::~UnionShape() {
    delete shape1;
    delete shape2;
}

std::pair<double, double> UnionShape::distance(const Point &point) const {
    auto distance1 = shape1->distance(point), distance2 = shape2->distance(point);
    return distance1.first < distance2.first ? distance1 : distance2;
}

std::vector<Point> UnionShape::intersect(const Line &line) {
    // TODO
    return std::vector<Point>();
}
