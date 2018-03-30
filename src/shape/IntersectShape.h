//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_INTERSECTSHAPE_H
#define CPPLIGHT_INTERSECTSHAPE_H

#include "Shape.h"

class IntersectShape : virtual public Shape {
    private:
        const Shape *shape1;
        const Shape *shape2;

    public:
        IntersectShape(const Shape *shape1, const Shape *shape2);

        ~IntersectShape() override;

        std::set<IntersectPoint> intersect(const Radial &line) const override;

        long hashCode() const override;

        bool isInside(const Point &point) const override;
};

#endif //CPPLIGHT_INTERSECTSHAPE_H
