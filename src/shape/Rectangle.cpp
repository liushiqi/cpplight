//
// Created by liu on 17-12-25.
//

#include "Rectangle.h"

Rectangle::Rectangle(const Point &center, const Vector &halfWidth, const Vector &halfHeight,
                     double emissive) : Shape(emissive), center(center), halfWidthVector(halfWidth),
                                        halfHeightVector(halfHeight) {}

Rectangle::Rectangle(const Point &center, double width, double height, double rotate,
                     double emissive) : Shape(emissive), center(center),
                                        halfWidthVector(width / 2 * std::cos(rotate), width / 2 * std::sin(rotate)),
                                        halfHeightVector(-height / 2 * std::sin(rotate),
                                                         height / 2 * std::cos(rotate)) {}

Rectangle::Rectangle(double centerX, double centerY, double width, double height, double rotate, double emissive) :
        Rectangle(Point(centerX, centerY), width, height, rotate, emissive) {}

Rectangle::~Rectangle() = default;

std::pair<double, double> Rectangle::distance(const Point &point) const {
    Vector relative = point - center;
    double widthDistance = halfWidthVector * relative / halfWidthVector.length();
    double heightDistance = halfHeightVector * relative / halfHeightVector.length();
    if (widthDistance > halfWidthVector.length()) {
        if (heightDistance > halfHeightVector.length()) {
            return std::make_pair((relative - halfHeightVector - halfWidthVector).length(), emissive);
        } else if (heightDistance < -halfHeightVector.length()) {
            return std::make_pair((relative + halfHeightVector - halfWidthVector).length(), emissive);
        } else {
            return std::make_pair(std::abs(widthDistance) - halfWidthVector.length(), emissive);
        }
    } else if (widthDistance < -halfWidthVector.length()) {
        if (heightDistance > halfHeightVector.length()) {
            return std::make_pair((relative - halfHeightVector + halfWidthVector).length(), emissive);
        } else if (heightDistance < -halfHeightVector.length()) {
            return std::make_pair((relative + halfHeightVector + halfWidthVector).length(), emissive);
        } else {
            return std::make_pair(std::abs(widthDistance) - halfWidthVector.length(), emissive);
        }
    } else {
        if (std::abs(heightDistance) > halfHeightVector.length()) {
            return std::make_pair(std::abs(heightDistance) - halfHeightVector.length(), emissive);
        } else {
            return std::make_pair(std::max(std::abs(widthDistance) - halfWidthVector.length(),
                                           std::abs(heightDistance) - halfHeightVector.length()), emissive);
        }
    }
}
