//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_SHAPE_H
#define CPPLIGHT_SHAPE_H

#include <random>
#include <set>
#include "Point.h"
#include "Line.h"

class Shape {
    protected:
        double emissive;

    public:
        explicit Shape(double emissive);

        virtual ~Shape() = default;

        virtual std::pair<double, double> distance(const Point &point) const = 0;

        virtual std::set<IntersectPoint> intersect(const Line &line) = 0;

        double getEmissive() { return emissive; }

        double setEmissive(double emissive) { this->emissive = emissive; }
};

#endif //CPPLIGHT_SHAPE_H
