//
// Created by liu on 17-12-24.
//

#include "SubtractShape.h"

SubtractShape::SubtractShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

SubtractShape::~SubtractShape() {
    delete shape1;
    delete shape2;
}

std::set<IntersectPoint> SubtractShape::intersect(const Line &line) {
    // TODO
    return std::set<IntersectPoint>();
}

long SubtractShape::hashCode() const {
    return shape1->hashCode() + shape2->hashCode() * 10000;
}
