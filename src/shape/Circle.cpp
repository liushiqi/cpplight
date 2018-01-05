//
// Created by liu on 17-12-22.
//

#include <cmath>
#include <set>
#include "Circle.h"

Circle::Circle(const Point &center, double radius, double emissive) : Shape(emissive), center(center), radius(radius) {}

Circle::Circle(double centerX, double centerY, double radius, double emissive) : Shape(emissive),
                                                                                 center(centerX, centerY),
                                                                                 radius(radius) {}

Circle::~Circle() = default;

std::pair<double, double> Circle::distance(const Point &point) const {
    double xDistance = point.x - center.x, yDistance = point.y - center.y;
    return std::make_pair(std::sqrt(xDistance * xDistance + yDistance * yDistance) - radius, emissive);
}

std::set<IntersectPoint> Circle::intersect(const Line &line) {
    std::set<IntersectPoint> points;
    points.insert(IntersectPoint(line.point, 0.0, this->emissive));
    Vector cenToPoi = line.point - center;
    double lenCenToPoi = cenToPoi.length();
    double lenDir = line.direction.length();
    double dot = cenToPoi * line.direction;
    double delta = 4 * (std::pow(dot, 2) - std::pow(lenDir * lenCenToPoi, 2) +
                        std::pow(lenDir * radius, 2));
    if (delta > 0) {
        double n = (std::sqrt(delta) - 2 * dot) / (2 * std::pow(lenDir, 2));
        if (n > 0)
            points.insert(IntersectPoint(cenToPoi + center + line.direction * n, n * lenDir, this->emissive));
        n = (-std::sqrt(delta) - 2 * dot) / (2 * std::pow(lenDir, 2));
        if (n > 0)
            points.insert(IntersectPoint(cenToPoi + center + line.direction * n, n * lenDir, this->emissive));
    } else if (std::abs(delta) < 1e-6) {
        double n = -dot / std::pow(lenDir, 2);
        if (n > 0)
            points.insert(IntersectPoint(cenToPoi + line.direction * n, n * lenDir, this->emissive));
    }
    return points;
}
