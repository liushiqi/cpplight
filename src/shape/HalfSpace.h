//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_HALFSPACE_H
#define CPPLIGHT_HALFSPACE_H

#include "Shape.h"

class HalfSpace : virtual public Shape {
    private:
        Point base;
        Vector normal;

    public:
        HalfSpace(const Point &base, const Vector &normal, double emissive);

        HalfSpace(const Point &base, double normalX, double normalY, double emissive);

        HalfSpace(double baseX, double baseY, const Vector &normal, double emissive);

        HalfSpace(double baseX, double baseY, double normalX, double normalY, double emissive);

        ~HalfSpace() override;

        std::set<IntersectPoint> intersect(const Line &line) override;
};

#endif //CPPLIGHT_HALFSPACE_H
