//
// Created by liu on 17-12-24.
//

#ifndef CPPLIGHT_HALFSPACE_H
#define CPPLIGHT_HALFSPACE_H

#include "Shape.h"

/**
 * The shape is a line which contains the point <b>base</b>,<br>
 * and has a normal vector <b>normal</b>, along with a field<br>
 * aside the line defined by the direction of vector <b>normal</b>.<p>
 *
 * Using this class for a directional light is not suggested,<br>
 * you'd better use a big <b>Rectangle</b> instead.<p>
 *
 * If the class will be used as the sourceof light ,the <b>emissive</b><br>
 * of <b>HalfSpace</b> should be no more than 2.0, otherwise<br>
 * the scene will be too bright to see it.
 *
 * @author liushiqi
 * @see Shape
 */
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

        std::set<IntersectPoint> intersect(const Line &line) const override;

        long hashCode() const override;

        bool isInside(const Point &point) const override;
};

#endif //CPPLIGHT_HALFSPACE_H
