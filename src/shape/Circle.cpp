//
// Created by liu on 17-12-22.
//

#include <cmath>
#include "Circle.h"

Circle::Circle(const Point &center, double radius, double emissive) : Shape(emissive), center(center), radius(radius) {}

Circle::Circle(double centerX, double centerY, double radius, double emissive) : Shape(emissive), center(centerX, centerY), radius(radius) {}

Circle::~Circle() = default;

std::pair<double, double> Circle::distance(const Point &point) const {
    double xDistance = point.x - center.x, yDistance = point.y - center.y;
    return std::make_pair(std::sqrt(xDistance * xDistance + yDistance * yDistance) - radius, emissive);
}
