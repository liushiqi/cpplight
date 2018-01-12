//
// Created by liu on 17-12-24.
//

#include "UnionShape.h"

UnionShape::UnionShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

UnionShape::~UnionShape() {
    delete shape1;
    delete shape2;
}

std::set<IntersectPoint> UnionShape::intersect(const Line &line) const {
    // TODO
    return std::set<IntersectPoint>();
}

long UnionShape::hashCode() const {
    return shape1->hashCode() + shape2->hashCode() * 1000;
}

bool UnionShape::isInside(const Point &point) const {
    return shape1->isInside(point) || shape2->isInside(point);
}
