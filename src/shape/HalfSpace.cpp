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

std::set<IntersectPoint> HalfSpace::intersect(const Line &line) const {
    std::set<IntersectPoint> intersect = std::set<IntersectPoint>();
    intersect.insert(IntersectPoint(line.point, 0.0, this->emissive));
    Vector pointToBase = base - line.point;
    if (pointToBase * normal == 0) {
        intersect.insert(IntersectPoint(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(),
                                        std::numeric_limits<double>::max(), this->emissive));
    } else if (line.direction * normal == 0) {
        if (pointToBase * normal <= 0)
            intersect.insert(IntersectPoint(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(),
                                            std::numeric_limits<double>::max(), this->emissive));
    } else {
        double proportion = pointToBase * normal / (line.direction * normal);
        if (proportion >= 0) {
            intersect.insert(IntersectPoint(line.point + line.direction * proportion,
                                            line.direction.length() * proportion, this->emissive));
        } else {
            if (pointToBase * normal < 0)
                intersect.insert(IntersectPoint(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(),
                                                std::numeric_limits<double>::max(), this->emissive));
        }
    }
    return intersect;
}

long HalfSpace::hashCode() const {
    return static_cast<long>(base.x + base.y * 10 + normal.x * 100 + normal.y * 1000 + emissive * 10000);
}

bool HalfSpace::isInside(const Point &point) const {
    return (point - base) * normal >= 0;
}
