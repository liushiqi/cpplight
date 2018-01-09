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

        virtual std::set<IntersectPoint> intersect(const Line &line) = 0;

        double getEmissive() { return emissive; }

        void setEmissive(double emissive) { this->emissive = emissive; }

        bool operator==(Shape &another);

        virtual long hashCode() const = 0;
};

#endif //CPPLIGHT_SHAPE_H
