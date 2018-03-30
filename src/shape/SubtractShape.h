//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_SUBSTRACTSHAPE_H
#define CPPLIGHT_SUBSTRACTSHAPE_H

#include "Shape.h"

class SubtractShape : virtual public Shape {
    private:
        const Shape *shape1;
        const Shape *shape2;

    public:
        SubtractShape(const Shape *shape1, const Shape *shape2);

        ~SubtractShape() override;

        std::set<IntersectPoint> intersect(const Radial &radial) const override;

        long hashCode() const override;

        bool isInside(const Point &point) const override;
};

#endif //CPPLIGHT_SUBSTRACTSHAPE_H
