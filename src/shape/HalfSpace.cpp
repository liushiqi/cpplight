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

std::pair<double, double> HalfSpace::distance(const Point &point) const {
    return std::make_pair((point.x - base.x) * normal.x + (point.y - base.y) * normal.y, emissive);
}

std::vector<Point> HalfSpace::intersect(const Line &line) {
    // TODO
    return std::vector<Point>();
}
