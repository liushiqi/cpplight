//
// Created by liu on 17-12-22.
//

#include <cmath>
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

std::vector<Point> Circle::intersect(const Line &line) {
    std::vector<Point> points;
    Vector centerToPoint = line.point - center;
    double lengthCenterToPoint = centerToPoint.length();
    double lengthDirection = line.direction.length();
    double dot = centerToPoint * line.direction;
    double delta = 4 * (std::pow(dot, 2) - std::pow(lengthDirection * lengthCenterToPoint, 2) +
                        std::pow(lengthDirection * radius, 2));
    if (delta > 0) {
        double n = (std::sqrt(delta) - 2 * dot) / (2 * std::pow(lengthDirection, 2));
        points.push_back(centerToPoint + center + line.direction * n);
        n = (-std::sqrt(delta) - 2 * dot) / (2 * std::pow(lengthDirection, 2));
        points.push_back(centerToPoint + center + line.direction * n);
    } else if (std::abs(delta) < 1e-6) {
        double n = -dot / std::pow(lengthDirection, 2);
        points.push_back(centerToPoint + line.direction * n);
    }
    return points;
}
