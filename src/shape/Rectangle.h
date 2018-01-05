//
// Created by liu on 17-12-25.
//

#ifndef CPPLIGHT_RECTANGLE_H
#define CPPLIGHT_RECTANGLE_H

#include "Shape.h"

class Rectangle : virtual public Shape {
    private:
        Point center;
        Vector halfWidthVector, halfHeightVector;

    public:
        Rectangle(const Point &center, const Vector &halfWidth, const Vector &halfHeight, double emissive);

        Rectangle(const Point &center, double width, double height, double rotate, double emissive);

        Rectangle(double centerX, double centerY, double width, double height, double rotate, double emissive);

        ~Rectangle() override;

        std::pair<double, double> distance(const Point &point) const override;

        std::vector<Point> intersect(const Line &line) override;
};

#endif //CPPLIGHT_RECTANGLE_H
