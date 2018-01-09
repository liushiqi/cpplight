//
// Created by liu on 17-12-24.
//

#include "Shape.h"

Shape::Shape(double emissive) : emissive(emissive) {}

bool Shape::operator==(Shape &another) {
    return this->hashCode() == another.hashCode();
}
