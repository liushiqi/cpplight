//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_CIRCLE_H
#define CPPLIGHT_CIRCLE_H

#include "Shape.h"

class Circle : virtual public Shape {
    private:
        Point center;
        double radius;

    public:
        Circle(const Point &center, double radius, double emissive);

        Circle(double centerX, double centerY, double radius, double emissive);

        ~Circle() override;

        std::set<IntersectPoint> intersect(const Line &line) override;

        long hashCode() const override;
};

#endif //CPPLIGHT_CIRCLE_H
