//
// Created by liu on 17-12-24.
//

#include "HalfSpace.h"

HalfSpace::HalfSpace(const Point &base, const Vector &normal,
                     double emissive) : Shape(emissive), base(base), normal(normal) {}

HalfSpace::HalfSpace(const Point &base, double normalX, double normalY,
                     double emissive) : Shape(emissive), base(base), normal(normalX, normalY) {}

HalfSpace::HalfSpace(double baseX, double baseY, const Vector &normal,
                     double emissive) : Shape(emissive), base(baseX, baseY), normal(normal) {}

HalfSpace::HalfSpace(double baseX, double baseY, double normalX, double normalY,
                     double emissive) : Shape(emissive), base(baseX, baseY), normal(normalX, normalY) {}

HalfSpace::~HalfSpace() = default;

std::set<IntersectPoint> HalfSpace::intersect(const Line &line) {
    // TODO
    return std::set<IntersectPoint>();
}
