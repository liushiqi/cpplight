//
// Created by liu on 17-12-30.
//

#include "Radial.h"

Radial::Radial(const Point &point, const Vector &direction) : point(point), direction(direction) {}

Radial::Radial(const Point &point, double directionX, double directionY) : point(point),
                                                                           direction(directionX, directionY) {}

Radial::~Radial() = default;
