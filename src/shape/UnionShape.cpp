//
// Created by liu on 17-12-24.
//

#include "UnionShape.h"

UnionShape::UnionShape(const Shape *shape1, const Shape *shape2) : Shape(0.0), shape1(shape1), shape2(shape2) {}

UnionShape::~UnionShape() = default;

std::set<IntersectPoint> UnionShape::intersect(const Radial &line) const {
    auto intersect1 = shape1->intersect(line);
    auto intersect2 = shape2->intersect(line);
    auto intersect = std::set<IntersectPoint>();
    intersect.insert(IntersectPoint(line.point, 0.0, 0.0));
    IntersectPoint currentPoint = IntersectPoint(line.point, 0.0, 0.0);
    if (intersect1.size() == 1 && intersect2.size() == 1) {}
    else if (intersect1.size() == 1) {
        for (auto &&point : intersect2) {
            if (isInside(point)) {
                intersect.insert(point);
            }
        }
    } else if (intersect2.size() == 1) {
        for (auto &&point : intersect1) {
            if (isInside(point)) {
                intersect.insert(point);
            }
        }
    } else
        for (auto point1 = ++intersect1.begin(), point2 = ++intersect2.begin();;) {
            if (point1 == intersect1.end() && point2 == intersect2.end())
                break;
            else if (point1 == intersect1.end()) {
                if (isInside(*point2 / 2 + currentPoint / 2)) {
                    intersect.insert(currentPoint);
                    intersect.insert(*point2);
                }
                currentPoint = *point2;
                point2++;
            } else if (point2 == intersect2.end()) {
                if (isInside(*point1)) {
                    intersect.insert(currentPoint);
                    intersect.insert(*point1);
                }
                currentPoint = *point1;
                point1++;
            } else {
                if (*point1 < *point2) {
                    if (isInside(*point1 / 2 + currentPoint / 2)) {
                        intersect.insert(currentPoint);
                        intersect.insert(*point1);
                    }
                    currentPoint = *point1;
                    point1++;
                } else {
                    if (isInside(*point2 / 2 + currentPoint / 2)) {
                        intersect.insert(currentPoint);
                        intersect.insert(*point2);
                    }
                    currentPoint = *point2;
                    point2++;
                }
            }
        }
    return intersect;
}

long UnionShape::hashCode() const {
    return shape1->hashCode() + shape2->hashCode() * 1000;
}

bool UnionShape::isInside(const Point &point) const {
    return shape1->isInside(point) || shape2->isInside(point);
}
