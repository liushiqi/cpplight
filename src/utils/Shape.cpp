//
// Created by liu on 17-12-24.
//

#include "Shape.h"

Shape::Shape(double luminance) : luminance(luminance) {}

bool Shape::operator==(Shape &another) {
    return this->hashCode() == another.hashCode();
}
