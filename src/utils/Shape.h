//
// Created by liu on 17-12-22.
//

#ifndef CPPLIGHT_SHAPE_H
#define CPPLIGHT_SHAPE_H

#include <random>
#include <set>
#include "Point.h"
#include "Radial.h"

class Shape {
    protected:
        double luminance;

    public:
        /**
         * Constructor of the virtual class shape.
         *
         * @param luminance the luminance of a light source, 0.0 if the shape not luminescence.
         */
        explicit Shape(double luminance);

        virtual ~Shape() = default;

        /**
         * Calculate the intersect points of this shape and the given radial. Returns the base point of the radial
         *
         *
         * @param radial the radial to be intersected with.
         * @return the set of intersect points.
         */
        virtual std::set<IntersectPoint> intersect(const Radial &radial) const = 0;

        double getEmissive() const { return luminance; }

        void setEmissive(double emissive) { this->luminance = emissive; }

        bool operator==(Shape &another);

        virtual long hashCode() const = 0;

        virtual bool isInside(const Point &point) const = 0;
};

#endif //CPPLIGHT_SHAPE_H
