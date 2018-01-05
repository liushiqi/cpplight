//
// Created by liu on 17-12-30.
//

#include "Line.h"

Line::Line(const Point &point, const Vector &direction) : point(point), direction(direction) {}

Line::Line(const Point &point, double directionX, double directionY) : point(point),
                                                                       direction(directionX, directionY) {}

Line::~Line() = default;
