//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_UNIONSHAPE_H
#define CPPLIGHT_UNIONSHAPE_H

#include "Shape.h"

class UnionShape : virtual public Shape {
    private:
        const Shape *shape1;
        const Shape *shape2;

    public:
        UnionShape(const Shape *shape1, const Shape *shape2);

        ~UnionShape() override;

        std::pair<double, double> distance(const Point &point) const override;

        std::set<IntersectPoint> intersect(const Line &line) override;
};

#endif //CPPLIGHT_UNIONSHAPE_H
