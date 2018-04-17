//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_UNIONSHAPE_H
#define CPPLIGHT_UNIONSHAPE_H

#include "../utils/Shape.h"

class UnionShape : virtual public Shape {
    private:
        const Shape *shape1;
        const Shape *shape2;

    public:
        UnionShape(const Shape *shape1, const Shape *shape2);

        ~UnionShape() override;

        std::set<IntersectPoint> intersect(const Radial &line) const override;

        long hashCode() const override;

        bool isInside(const Point &point) const override;
};

#endif //CPPLIGHT_UNIONSHAPE_H
