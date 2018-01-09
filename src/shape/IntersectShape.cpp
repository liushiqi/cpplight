//
// Created by liu on 17-12-24.
//

#include "IntersectShape.h"

IntersectShape::IntersectShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

IntersectShape::~IntersectShape() {
    delete shape1;
    delete shape2;
}

std::set<IntersectPoint> IntersectShape::intersect(const Line &line) {
    // TODO
    return std::set<IntersectPoint>();
}

long IntersectShape::hashCode() const {
    return shape1->hashCode() * 100 + shape2->hashCode() * 100;
}
