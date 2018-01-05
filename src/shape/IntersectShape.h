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

        std::pair<double, double> distance(const Point &point) const override;

        std::set<std::pair<Point, double>, Compare> intersect(const Line &line) override;
};

#endif //CPPLIGHT_INTERSECTSHAPE_H
