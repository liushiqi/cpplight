//
// Created by liu on 17-12-25.
//

#include "Rectangle.h"
#include "Scene.h"

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

std::set<IntersectPoint> Rectangle::intersect(const Radial &line) const {
    std::set<IntersectPoint> intersect = std::set<IntersectPoint>();
    intersect.insert(IntersectPoint(line.point, 0.0, this->luminance));
    Point leftDown = center - halfWidthVector - halfHeightVector;
    Vector lineToLD = leftDown - line.point;
    double delta = line.direction.x * halfWidthVector.y - halfWidthVector.x * line.direction.y;
    if (delta != 0) {
        double t1 = (lineToLD.x * line.direction.y - lineToLD.y * line.direction.x) / delta;
        double t2 = (lineToLD.x * halfWidthVector.y - lineToLD.y * halfWidthVector.x) / delta;
        if (t1 >= 0 && t1 < 2 + Scene::EPSILON && t2 > 0)
            intersect.insert(IntersectPoint(line.point + line.direction * t2,
                                            line.direction.length() * t2, this->luminance));
    }
    delta = line.direction.x * halfHeightVector.y - halfHeightVector.x * line.direction.y;
    if (delta != 0) {
        double t1 = (lineToLD.x * line.direction.y - lineToLD.y * line.direction.x) / delta;
        double t2 = (lineToLD.x * halfHeightVector.y - lineToLD.y * halfHeightVector.x) / delta;
        if (t1 > 0 && t1 <= 2 + Scene::EPSILON && t2 > 0)
            intersect.insert(IntersectPoint(line.point + line.direction * t2,
                                            line.direction.length() * t2, this->luminance));
    }
    Point leftUp = leftDown + halfHeightVector * 2;
    Vector lineToLU = leftUp - line.point;
    delta = line.direction.x * halfWidthVector.y - halfWidthVector.x * line.direction.y;
    if (delta != 0) {
        double t1 = (lineToLU.x * line.direction.y - lineToLU.y * line.direction.x) / delta;
        double t2 = (lineToLU.x * halfWidthVector.y - lineToLU.y * halfWidthVector.x) / delta;
        if (t1 > 0 && t1 <= 2 + Scene::EPSILON && t2 > 0)
            intersect.insert(IntersectPoint(line.point + line.direction * t2,
                                            line.direction.length() * t2, this->luminance));
    }
    Point rightDown = leftDown + halfWidthVector * 2;
    Vector lineToRD = rightDown - line.point;
    delta = line.direction.x * halfHeightVector.y - halfHeightVector.x * line.direction.y;
    if (delta != 0) {
        double t1 = (lineToRD.x * line.direction.y - lineToRD.y * line.direction.x) / delta;
        double t2 = (lineToRD.x * halfHeightVector.y - lineToRD.y * halfHeightVector.x) / delta;
        if (t1 >= 0 && t1 < 2 + Scene::EPSILON && t2 > 0)
            intersect.insert(IntersectPoint(line.point + line.direction * t2,
                                            line.direction.length() * t2, this->luminance));
    }
    return intersect;
}

long Rectangle::hashCode() const {
    return static_cast<long>(center.x + center.y * 10 + halfWidthVector.x * 100 + halfWidthVector.y * 1000 +
                             halfHeightVector.x * 10000 + halfHeightVector.y * 100000 + luminance * 1000000);
}

bool Rectangle::isInside(const Point &point) const {
    return std::abs((point - center) * halfWidthVector) <= halfWidthVector.length()
           && std::abs((point - center) * halfHeightVector) <= halfHeightVector.length();
}
