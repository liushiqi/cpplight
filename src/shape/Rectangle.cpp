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

std::set<IntersectPoint> Rectangle::intersect(const Line &line) {
    // TODO
    return std::set<IntersectPoint>();
}
