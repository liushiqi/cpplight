//
// Created by liu on 17-12-24.
//

#include "UnionShape.h"

UnionShape::UnionShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

UnionShape::~UnionShape() {
    delete shape1;
    delete shape2;
}

std::set<IntersectPoint> UnionShape::intersect(const Line &line) {
    // TODO
    return std::set<IntersectPoint>();
}
