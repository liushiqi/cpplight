//
// Created by liu on 17-12-24.
//

#include "IntersectShape.h"

IntersectShape::IntersectShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

IntersectShape::~IntersectShape() {
    delete shape1;
    delete shape2;
}

std::set<IntersectPoint> IntersectShape::intersect(const Line &line) const {
    // auto intersect1 = shape1->intersect(line);
    // auto intersect2 = shape2->intersect(line);
    // TODO
    return std::set<IntersectPoint>();
}

long IntersectShape::hashCode() const {
    return shape1->hashCode() + shape2->hashCode() * 10;
}
